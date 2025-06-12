#include <iostream>
using namespace std;

class Queues
{
private:
    static const int max =5;
    int FRONT, REAR;
    int queue_array[5];

public:
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }

    void insert()
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n";
            return;
        }

        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;
        }
        else
        {
            if (REAR == max -1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    void remove()
    {
        if (FRONT == -1)
        {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: " << queue_array [FRONT] << "\n";

        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }
    void display()
    {
        int FRONT_position = FRONT;
        int REAR_position = REAR;

        if (FRONT == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
        else
        {
            while (FRONT_position <= max - 1)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }

            FRONT_position = 0;

            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
    }

};

int main()
{
    Queues q;
    char ch;

    while (true)
    {
       try
       {
            cout << "Menu" << endl;
            cout << "1. implement insert operation" << endl;
            cout << "2. implement delete operation" << endl;
            cout << "3. Diplay values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter yuor choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch(ch)
            {
                case '1':
                {
                    
                    q.insert();
                    break;
                }
                case '2':
                {

                    q.remove();
                    break;
                }
                case '3':
                {
                    q.display();
                    break;
                }
                case '4':
                {
                    return 0;
                }
                default:
                {
                    cout << "Invalid option!!" << endl;
                    break;
                }
            }
       }
       catch(const std::exception& e)
       {
            cout << "Check for the values entered." << endl;
       }
       
        
    }

    return 0;
}