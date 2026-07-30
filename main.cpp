#include <iostream>
using namespace std;

const int WIDTH = 30;
const int HEIGHT = 10;

int main() {
    int paddle = HEIGHT / 2;
    int ballX = WIDTH / 2;
    int ballY = HEIGHT / 2;
    int dx = 1, dy = 1;

    while (true) {
        // Draw
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {

                if (x == 0 || x == WIDTH - 1)
                    cout << "|";
                else if (y == 0 || y == HEIGHT - 1)
                    cout << "-";
                else if (x == 2 && y >= paddle - 1 && y <= paddle + 1)
                    cout << "#";
                else if (x == ballX && y == ballY)
                    cout << "O";
                else
                    cout << " ";
            }
            cout << '\n';
        }

        cout << "\nMove paddle (w = up, s = down, q = quit): ";
        char move;
        cin >> move;

        if (move == 'q')
            break;
        if (move == 'w' && paddle > 2)
            paddle--;
        if (move == 's' && paddle < HEIGHT - 3)
            paddle++;

        // Move ball
        ballX += dx;
        ballY += dy;

        // Bounce off top/bottom
        if (ballY == 1 || ballY == HEIGHT - 2)
            dy *= -1;

        // Bounce off paddle
        if (ballX == 3 && ballY >= paddle - 1 && ballY <= paddle + 1)
            dx = 1;

        // Bounce off right wall
        if (ballX == WIDTH - 2)
            dx = -1;

        // Missed paddle
        if (ballX == 1) {
            cout << "\nGame Over! You missed the ball.\n";
            break;
        }

        // Clear screen by printing blank lines
        cout << string(30, '\n');
    }

    return 0;
}
