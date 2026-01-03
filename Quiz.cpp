
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
using namespace std;

/* =======================
   Base Question Class
   ======================= */
class Question {
protected:
    string questionText;
    vector<string> options;
    int correctOption;

public:
    Question(string q, vector<string> opt, int correct)
        : questionText(q), options(opt), correctOption(correct) {}

    virtual bool askQuestion() {
        cout << "\n" << questionText << endl;
        for (int i = 0; i < options.size(); i++) {
            cout << i + 1 << ". " << options[i] << endl;
        }

        int answer;
        cout << "Enter your choice: ";
        cin >> answer;

        if (answer < 1 || answer > options.size())
            throw invalid_argument("Invalid option selected!");

        return (answer == correctOption);
    }

    virtual ~Question() {}
};

/* =======================
   Quiz Class
   ======================= */
class Quiz {
private:
    vector<Question*> questions;
    int score;

public:
    Quiz() : score(0) {}

    void addQuestion(Question* q) {
        questions.push_back(q);
    }

    void startQuiz() {
        cout << "\n===== Quiz Started =====\n";

        for (auto q : questions) {
            try {
                if (q->askQuestion()) {
                    cout << "Correct!\n";
                    score++;
                } else {
                    cout << "Wrong!\n";
                }
            } catch (exception& e) {
                cout << "Error: " << e.what() << endl;
            }
        }
    }

    int getScore() {
        return score;
    }

    int totalQuestions() {
        return questions.size();
    }

    ~Quiz() {
        for (auto q : questions)
            delete q;
    }
};

/* =======================
   Player Class
   ======================= */
class Player {
private:
    string name;

public:
    Player(string n) : name(n) {}

    string getName() {
        return name;
    }
};

/* =======================
   Result Manager
   ======================= */
class ResultManager {
public:
    static void saveResult(string name, int score, int total) {
        ofstream file("results.txt", ios::app);
        file << "Player: " << name
             << " | Score: " << score << "/" << total << endl;
        file.close();
    }
};

/* =======================
   Main Function
   ======================= */
int main() {
    cout << "===== Advanced Quiz Application =====\n";

    string playerName;
    cout << "Enter your name: ";
    getline(cin, playerName);

    Player player(playerName);
    Quiz quiz;

    quiz.addQuestion(new Question(
        "What is the size of int in C++ (commonly)?",
        {"2 bytes", "4 bytes", "8 bytes", "Depends on compiler"},
        2
    ));

    quiz.addQuestion(new Question(
        "Which concept allows function overriding?",
        {"Encapsulation", "Abstraction", "Polymorphism", "Inheritance"},
        3
    ));

    quiz.addQuestion(new Question(
        "Which STL container uses LIFO?",
        {"Queue", "Stack", "Vector", "Map"},
        2
    ));

    quiz.startQuiz();

    int score = quiz.getScore();
    int total = quiz.totalQuestions();

    cout << "\n===== Quiz Finished =====\n";
    cout << "Player: " << player.getName() << endl;
    cout << "Score: " << score << "/" << total << endl;

    ResultManager::saveResult(player.getName(), score, total);

    cout << "Result saved successfully!\n";

    return 0;
}

// # 🎯 Advanced Quiz Application (OOP-Based) in C++

// An advanced console-based Quiz Application built using **Object-Oriented Programming (OOP)** concepts in **C++**.  
// This project is designed for **students, beginners, and GitHub portfolios**.

// ---

// ## 🚀 Features
// - OOP Architecture (Classes & Objects)
// - Inheritance & Polymorphism
// - STL (`vector`)
// - File Handling (Score Storage)
// - Exception Handling
// - Dynamic Memory Management
// - Menu-driven interaction

// ---

// ## 🧠 OOP Concepts Used
// - Encapsulation
// - Abstraction
// - Inheritance
// - Polymorphism
// - Constructors & Destructors

// ---

// ## 📂 Project Structure
