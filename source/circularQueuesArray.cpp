/**
 * @mainpage Documentation Circular Queues
 * 
 * @section Introduction
 * projek ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular arrays.
 * 
 * @section Operations
 * projek ini memiliki beberapa operasi antara lain:
 * 1. Insert
 * 2. Delete
 * 3. Display
 * 
 * @section Cara pengunaan 
 * Berikut beberapa menu yang di gunakan:
 * 1. en queue
 * 2. de queue
 * 3. display
 * 4. exit
 * 
 * @author Profil
 * - nama : ichlas bintang saputra
 * - nim : 20240140101
 * - kelas : B
 * 
 * @brief
 * @version 1.0
 * @date 2025-06-24
 * 
 * @copyright ilas@umy.ac.id (c) 2025
 */
#include <iostream>
using namespace std;
/**
 * @class Queues
 * @brief class ini untuk operasi lengkap queues
 * 
 * 
 */

class Queues
{
private:
    static const int max =5; ///< variabel private front untuk menyimpan posisi depan antrian
    int FRONT; ///< variabel private rear untuk menyimpan posisi belakang antrian
    int REAR; ///<variabel private max untuk menyimpan ukuran maximum antrian
    int queue_array[5]; ///<variabel private queue_array untuk menyimpan elemen antrian

public:
    /**
     * @brief Construct a new Queues objek
     * set default queues null
     * with front = -1 and rear = -1
     */
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief method untuk memasukan data dalam antrian
     * data dimasukan dalam variabel queue_array
     */

    void insert()
    {
        int num;///<variable num untuk menyimpan nilai
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        // cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n";
            return;
        }

        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;
        }

        else
        {
            // jika REAR berada di posisi terkhir array, kembali ke awal array
            if (REAR == max -1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;

    }

    /**
     * @brief method untuk menghapus data dalam antrian
     * data dihapuskan dari dalam queue_array
     */

    void remove()
    {
        // Cek apakah antrian kosong
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

    /**
     * @brief method untuk menanpilkan data dalam antrian
     * data ditampilkan dari dalam variabel queue_array
     */

    void display()
    {
        int FRONT_position = FRONT;///< variabel front_position untuk enandakan posisi element
        int REAR_position = REAR;///< variabel rear_position untuk menandakan posisi element

        // Cek apakah antrian masih kosong
        if (FRONT == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        // Jika FRONT_position

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

    /**
     * @brief method utama untuk menjalankan program
     * 
     * @return int
     */

};

int main()
{
    Queues q;///<objek untuk menggunakan member yang ada pada class queue
    char ch;///< variabel ch untuk menyimpan pilihan pada menu yang diberikan

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