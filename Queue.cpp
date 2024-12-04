#include <iostream>

#include <queue>

#include <string>

#include <thread>

#include <chrono>

#include <mutex>

 

using namespace std;

 

class Person {

public:

    string name;

    string ticket_number;

 

    Person(string n, string t) : name(n), ticket_number(t) {}

};

 

class Queue {

private:

    queue<Person> q;

    int ticket_counter;

    mutex mtx;

 

public:

    Queue() : ticket_counter(1) {}

 

    void enqueue(const string& name) {

        lock_guard<mutex> lock(mtx);

        string ticket = "Ticket #" + to_string(ticket_counter++);

        q.push(Person(name, ticket));

        cout << name << " added to the queue with " << ticket << endl;

    }

 

    void autoDequeue() {

        while (true) {

            this_thread::sleep_for(chrono::minutes(1));

            lock_guard<mutex> lock(mtx);

            if (!q.empty()) {

                Person person = q.front();

                q.pop();

                cout << "\nDequeue: " << person.name << " received a ticket (" << person.ticket_number << ")" << endl;

                if (!q.empty()) {

                    cout << "Next in line: " << q.front().name << " (" << q.front().ticket_number << ")" << endl;

                }

            }

        }

    }

 

    bool isEmpty() {

        lock_guard<mutex> lock(mtx);

        return q.empty();

    }

 

    int size() {

        lock_guard<mutex> lock(mtx);

        return q.size();

    }

 

    void peek() {

        lock_guard<mutex> lock(mtx);

        if (!q.empty()) {

            cout << "Next in line: " << q.front().name << " (" << q.front().ticket_number << ")" << endl;

        } else {

            cout << "The queue is empty." << endl;

        }

    }

 

    void position(const string& name_or_ticket) {

        lock_guard<mutex> lock(mtx);

        int pos = 1;

        bool found = false;

        queue<Person> temp = q;

 

        while (!temp.empty()) {

            Person person = temp.front();

            temp.pop();

            if (person.name == name_or_ticket || person.ticket_number == name_or_ticket) {

                cout << person.name << " is currently at position " << pos << " in the queue." << endl;

                found = true;

                break;

            }

            pos++;

        }

 

        if (!found) {

            cout << "Person not found in the queue." << endl;

        }

    }

};

 

void menu(Queue& concertQueue) {

    while (true) {

        cout << "\nWelcome to Olivia Rodrigo's Concert Ticketing System!" << endl;

        cout << "1. Enqueue a person" << endl;

        cout << "2. Check your position in the queue" << endl;

        cout << "3. Exit" << endl;

 

        int choice;

        cout << "Choose an option: ";

        cin >> choice;

        cin.ignore();

 

        if (choice == 1) {

            string name;

            cout << "Enter the name: ";

            getline(cin, name);

            concertQueue.enqueue(name);

            cout << "Queue size: " << concertQueue.size() << endl;

 

        } else if (choice == 2) {

            string name_or_ticket;

            cout << "Enter your name or ticket number: ";

            getline(cin, name_or_ticket);

            concertQueue.position(name_or_ticket);

 

        } else if (choice == 3) {

            cout << "Exiting the system. Goodbye!" << endl;

            break;

 

        } else {

            cout << "Invalid option. Please try again." << endl;

        }

    }

}

 

int main() {

    Queue concertQueue;

    thread autoDequeueThread(&Queue::autoDequeue, &concertQueue);

    menu(concertQueue);

    autoDequeueThread.detach();

    return 0;

}
