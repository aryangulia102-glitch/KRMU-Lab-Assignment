#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cctype>
using namespace std;

// -------- Patient Record (Linked List) --------
struct Patient
{
    int id;
    string name, date, treatment;
    Patient *next;
    Patient(int i, string n, string d, string t)
        : id(i), name(n), date(d), treatment(t), next(nullptr) {}
};

class Hospital
{
    Patient *head = nullptr;
    stack<Patient> undoStack;
    queue<Patient> emergencyQ;

public:
    void addPatient(int id, string n, string d, string t)
    {
        Patient *p = new Patient(id, n, d, t);
        p->next = head;
        head = p;
        undoStack.push(*p);
        cout << "✅ Patient record added successfully!\n";
    }

    void deletePatient(int id)
    {
        Patient *temp = head, *prev = nullptr;
        while (temp && temp->id != id)
        {
            prev = temp;
            temp = temp->next;
        }
        if (!temp)
        {
            cout << "⚠️ Patient ID not found.\n";
            return;
        }
        if (!prev)
            head = temp->next;
        else
            prev->next = temp->next;
        delete temp;
        cout << "🗑️ Record deleted.\n";
    }

    void showPatients()
    {
        if (!head)
        {
            cout << "📋 No patient records available.\n";
            return;
        }
        cout << "\n--- All Patient Records ---\n";
        for (Patient *p = head; p; p = p->next)
            cout << "ID: " << p->id << " | Name: " << p->name
                 << " | Date: " << p->date
                 << " | Treatment: " << p->treatment << "\n";
    }

    void undo()
    {
        if (undoStack.empty())
        {
            cout << "⚠️ Nothing to undo.\n";
            return;
        }
        deletePatient(undoStack.top().id);
        undoStack.pop();
        cout << "↩️ Last addition undone.\n";
    }

    void addEmergency(int id, string n, string d, string t)
    {
        emergencyQ.push(Patient(id, n, d, t));
        cout << "🚨 Emergency patient added to queue.\n";
    }

    void handleEmergency()
    {
        if (emergencyQ.empty())
        {
            cout << "✅ No pending emergencies.\n";
            return;
        }
        cout << "⚕️ Handling emergency: " << emergencyQ.front().name << "\n";
        emergencyQ.pop();
    }

    void calcBill(int days)
    {
        cout << "💰 Total Bill = Rs." << (1000 * days + 500) << "\n";
    }

    void evalPostfix(string exp)
    {
        stack<int> s;
        for (char c : exp)
        {
            if (isdigit(c))
                s.push(c - '0');
            else
            {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                if (c == '+')
                    s.push(a + b);
                else if (c == '-')
                    s.push(a - b);
                else if (c == '*')
                    s.push(a * b);
                else if (c == '/')
                    s.push(a / b);
            }
        }
        cout << "📦 Inventory Result: " << s.top() << "\n";
    }
};

// -------- Main --------
int main()
{
    Hospital h;
    int ch;
    do
    {
        cout << "\n===== 🏥 Hospital Patient Management Menu =====\n";
        cout << "1. Add Patient Record\n";
        cout << "2. Show All Records\n";
        cout << "3. Delete Patient Record\n";
        cout << "4. Undo Last Addition\n";
        cout << "5. Emergency Queue\n";
        cout << "6. Calculate Billing\n";
        cout << "7. Evaluate Inventory (Postfix)\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        if (ch == 1)
        {
            int id;
            string n, d, t;
            cout << "Enter Patient ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> n;
            cout << "Enter Admission Date (DD/MM): ";
            cin >> d;
            cout << "Enter Treatment Details: ";
            cin >> t;
            h.addPatient(id, n, d, t);
        }
        else if (ch == 2)
            h.showPatients();
        else if (ch == 3)
        {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            h.deletePatient(id);
        }
        else if (ch == 4)
            h.undo();
        else if (ch == 5)
        {
            int c;
            cout << "1. Add Emergency  2. Handle Emergency\nEnter choice: ";
            cin >> c;
            if (c == 1)
            {
                int id;
                string n, d, t;
                cout << "Enter Emergency Patient ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> n;
                cout << "Enter Date: ";
                cin >> d;
                cout << "Enter Treatment: ";
                cin >> t;
                h.addEmergency(id, n, d, t);
            }
            else
                h.handleEmergency();
        }
        else if (ch == 6)
        {
            int days;
            cout << "Enter number of treatment days: ";
            cin >> days;
            h.calcBill(days);
        }
        else if (ch == 7)
        {
            string exp;
            cout << "Enter postfix expression (e.g., 231*+9-): ";
            cin >> exp;
            h.evalPostfix(exp);
        }
    } while (ch != 8);

    cout << "\n👋 Exiting System. Stay Healthy!\n";
    return 0;
}
