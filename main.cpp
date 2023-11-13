#include <iostream>
#include <thread>

using namespace std;

class trash_guy {
    const string HAPPY_LEFT = "(> ^_^)>";
    const string HAPPY_RIGHT = "<(^_^ <)";

    const string THRASH = "🗑️";

    const int INTERVAL = 500;

    string text;

    static string repeat_space(const int times) {
        string result;
        for (int i = 0; i < times; ++i) result += ' ';
        return result;
    }

    void play() {
        char l;
        while ((l = text[0]) != '\0') {
            bool going_right = true;
            for (int left_space = 0, right_space = 10;;) {
                system("clear");
                cout << THRASH << repeat_space(left_space)
                     << (going_right ? HAPPY_LEFT : l + HAPPY_RIGHT)
                     << repeat_space(right_space) << text << endl;
                this_thread::sleep_for(chrono::milliseconds(INTERVAL));

                if (going_right && left_space >= 10) {
                    going_right = false;
                    left_space = 10;
                    right_space = 0;
                    text.erase(0, 1);
                } else if (!going_right && right_space >= 10) {
                    break;
                }
                if (going_right) {
                    left_space++;
                    right_space--;
                } else {
                    left_space--;
                    right_space++;
                }
            }
        }
    }

public:
    void add(string& _text) {
        this->text += _text;
        play();
    }
};

int main() {
    trash_guy guy;

    while (true) {
        string text;
        cin >> text;
        if (text == "end") {
            break;
        }
        guy.add(text);
    }
    return 0;
}
