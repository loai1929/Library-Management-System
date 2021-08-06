#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <conio.h>
using namespace std;

// Classes //
class Adress
{
public:
    char area[50], first_name[20], last_name[20], governorate[30], city[20], street_name[100], mobile[15], building_name[20], floor_no[10], apartment_no[5], nearest_landmark[50];
    //string area, first_name, last_name, governorate, city, street_name, mobile, building_name, floor_no, apartment_no, nearest_landmark;
    void dis_ad();
    void display_adress();
    void get_adress();
};

class Library
{
public:
    char author_name[100], book_name[50], str1[20], str2[50];
    long int pri, B, qua;
    Library()
    {
        strcpy(book_name, "Empty");
        strcpy(author_name, "Empty");
        strcpy(str1, "Empty");
        strcpy(str2, "Empty");
        pri = 0, B = 0, qua = 0;
    }
    // Member Functions Declaration
    void interface();
    void student();
    void librarian();
    void check_pass();
    void new_password();
    void getdata();
    void display(int);
    void booklist(int);
    int department(int);
    void modify();
    void search(int);
    void issue();
    void der(char[], int, int);
    void fine(int, int, int, int, int, int);
    void place_order();
    void display_purchases();
    //void proceed_checkout();
    void confirm_order();
};
// END OF CLASSES

// Funtion Prototype
void adress();
void proceed_checkout();
// Member FUNCTIONS DEFINITION
void Library::getdata()
{
    int i;
    fflush(stdin);
    cout << "Enter Book's details:\n\nBook's Name: ";
    cin.getline(book_name, 100);
    for (i = 0; i < book_name[i] != '\0'; i++)
    {
        if (book_name[i] >= 'a' && book_name[i] <= 'z')
            book_name[i] -= 32;
    }
    cout << "\nAuthor's Name: ";
    cin.getline(author_name, 50);
    cout << "\nPublicashing name: ";
    cin.getline(str2, 50);
    cout << "\nBook's ID: ";
    cin.getline(str1, 50);
    cout << "\nPrice: ";
    cin >> pri;
    cout << "\nThe Quantatiy: ";
    cin >> qua;
}
void Library::display(int i)
{
    cout << "\n\t\t\t\tBook's Name: " << book_name;
    cout << "\n\n\t\t\t\tAuthor's Name: " << author_name;
    cout << "\n\n\t\t\t\tBook's ID: " << str1;
    cout << "\n\n\t\t\t\tPublicashing name: " << str2;
    cout << "\n\n\t\t\t\tPrice: " << pri;
    cout << "\n\n\t\t\t\tThe Quantatiy: " << qua << endl;
}

void Adress::get_adress()
{

    cout << "\n\n\t\t\tMy Address:-\n\n\t\t\tFirst Name: ";
    cin.getline(first_name, 20);
    cout << "\n\n\t\t\tLast Name: ";
    cin.getline(last_name, 20);
    cout << "\n\n\t\t\tGovernorate: ";
    cin.getline(governorate, 30);
    cout << "\n\n\t\t\tCity: ";
    cin.getline(city, 20);
    cout << "\n\n\t\t\tArea: ";
    cin.getline(area, 50);
    cout << "\n\n\t\t\tStreet Name/NO. : ";
    cin.getline(street_name, 100);
    cout << "\n\n\t\t\tMobile: ";
    cin.getline(mobile, 15);
    cout << "\n\n\n\t\t\tBuilding Name/No. : ";
    cin.getline(building_name, 20);
    cout << "\n\n\t\t\tFloor No. : ";
    cin.getline(floor_no, 10);
    cout << "\n\n\t\t\tApartment No. : ";
    cin.getline(apartment_no, 5);
    cout << "\n\n\t\t\tNearest Landmark: ";
    cin.getline(nearest_landmark, 50);

    //getline(cin, first_name);
    //getline(cin, last_name);
    //getline(cin, governorate);
    //getline(cin, city);
    //getline(cin, area);
    //getline(cin, street_name);
    //getline(cin, mobile);
    //getline(cin, building_name);
    //getline(cin, floor_no);
    //getline(cin, apartment_no);
    //getline(cin, nearest_landmark);
}
void Adress::display_adress()
{

    cout << "\n\n\t\t\tFirst Name: " << first_name;
    cout << "\n\n\t\t\tLast Name: " << last_name;
    cout << "\n\n\t\t\tGovernorate: " << governorate;
    cout << "\n\n\t\t\tCity: " << city;
    cout << "\n\n\t\t\tArea: " << area;
    cout << "\n\n\t\t\tStreet Name/NO. : " << street_name;
    cout << "\n\n\t\t\tMobile: " << mobile;

    cout << "\n\n\n\t\t\tBuilding Name/No. : " << building_name;
    cout << "\n\n\t\t\tFloor No. : " << floor_no;
    cout << "\n\n\t\t\tFloor No. : " << apartment_no;
    cout << "\n\n\t\t\tNearest Landmark: " << nearest_landmark;
}
void Adress::dis_ad()
{
    ifstream iFile("shippingAddresses.dat", ios::binary);
    while (iFile.read((char *)this, sizeof(*this)))
    {
        display_adress();
    }
    iFile.close();
}
void adress()
{
    Adress ad;
    ifstream iFile("shippingAddresses.dat", ios::binary);
    while (iFile.read((char *)&ad, sizeof(Adress)))
    {
        ad.display_adress();
    }
    iFile.close();
}
void Library::place_order()
{
    int count = 0;
    char ch[100];
    ofstream oFile("purchases.dat", ios::app | ios::binary);
    ifstream iFile("BookList.txt", ios::binary);
    int choice, choose, quantaty, book_no, conf;
    vector<string> by_id;
    vector<string> by_name;
    cout << "\n\t\t\t\t________________\n\n\t\t\t\t1- To Order.\n\n\t\t\t\t2- Back.\n\n\t\t\t\tEnter: ";
    cin >> choice;
    fflush(stdin);
    if (choice == 1)
    {
        cout << "\n\n\t\t\t\tHow Many Books do you want: ";
        cin >> quantaty;
        fflush(stdin);
        for (int j = 1; j <= quantaty; j++)
        {
            cout << "\n\t\t\t\tBook " << j;
            cout << "\n\t\t\t\tChoose The book By\n\n\t\t\t\t1- Book's Name\n\n\t\t\t\t2- Book's ID\n\n\t\t\t\tChoose: ";
            cin >> choose;
            fflush(stdin);
            if (choose == 1)
            {
                cout << "\n\t\t\t\tBook's Name: ";
                cin.getline(ch, 100);
                by_name.push_back(ch);
            }
            else if (choose == 2)
            {
                cout << "\n\t\t\t\tBook's ID: ";
                cin.getline(ch, 100);
                by_id.push_back(ch);
            }
        }
        system("cls");
        cout << "\n\n\t\t1- Continue\n\n\t\t2- Back\n\n\t\t3- Menu\n\n\t\tEnter: ";
        cin >> conf;
        if (conf == 1)
        {
            system("cls");
            cout << "\n\n\t\t\t_____ The List of Orders ______\n";
            while (iFile.read((char *)this, sizeof(*this)))
            {
                int len_id = by_id.size(), len_name = by_name.size();
                for (int n = 0; n < len_id; n++)
                {
                    if (by_id[n] == str1)
                    {
                        count++;
                        oFile.write((char *)this, sizeof(*this));
                        cout << "\n\n\t\t\t /// Book Number " << count << " ///\n";
                        display(1);
                        break;
                    }
                }
                for (int n = 0; n < len_name; n++)
                {
                    if (by_name[n] == book_name)
                    {
                        count++;
                        oFile.write((char *)this, sizeof(*this));
                        cout << "\n\n\t\t\t /// Book Number " << count << " ///\n";
                        display(1);
                        break;
                    }
                }
            }
            oFile.close();
            iFile.close();
            cout << "\n\n\t\t\t1- PROCEED TO CHECKOUT\n\n\t\t\t2- Back\n\n\t\t\t3- Menu\n\n\t\t\tEnter: ";
            cin >> choice;
            fflush(stdin);
            switch (choice)
            {
            case 1:
                system("cls");
                proceed_checkout();
                break;
            case 2:
                booklist(1);
                break;
            case 3:
                system("cls");
                student();
                break;
            default:
                break;
            }
        }
        else if (conf == 2)
        {
            system("cls");
            department(2);
        }
        else
        {
            system("cls");
            student();
        }
    }
    else if (choice == 2)
    {
        system("cls");
        student();
    }
}
void proceed_checkout()
{
    Library lib;
    Adress ad;
    int choose;
    ofstream oFile("shipping addresses.dat", ios::binary | ios::app);
    ad.get_adress();
    oFile.write((char *)&ad, sizeof(Adress));
    oFile.close();
    cout << "\n\n\t\t\t1- Adress again\n\n\t\t\t2- Continue\n\n\t\t\tChoose: ";
    cin >> choose;
    fflush(stdin);
    switch (choose)
    {
    case 1:
        system("cls");
        proceed_checkout();
        break;
    case 2:
        system("cls");
        lib.confirm_order();
        break;
    default:
        break;
    }
}

void Library::display_purchases()
{
    ifstream iFile("purchases.dat", ios::binary);
    int count = 0;
    cout << "\n\t\t\t\tPurchases:\n";
    while (iFile.read((char *)this, sizeof(*this)))
    {
        count++;
        cout << "\n\n\t\t\t\t /// Book Number " << count << " ///\n";
        display(1);
    }
    iFile.close();
}
void Library::confirm_order()
{
    cout << "\n\n\t\t\tDelivery address\n";
    adress();
    cout << "\n\n\t\t\tSHOPPING CART\n";
    display_purchases();
}
void Library::booklist(int i)
{
    int count = 0, types;
    system("cls");
    types = department(i);
    system("cls");
    ifstream iFile("BookList.txt", ios::binary);
    if (!iFile)
        cout << "Can't Open That File\n";
    else
    {
        cout << "\n\n\t\t\t-------------View All Books----------------\t\t\n\n";
        while (iFile.read((char *)this, sizeof(*this)))
        {

            count++;
            cout << "\n\n\t\t\t\t********** Book's No.:" << count << " ********** \n";
            display(i);
        }
        if (i == 1)
        {
            // If User Want to Order
            place_order();
        }
    }
    cout << "\n\n\tPress Any Key To Continue. . .\n";
    getch();
    system("cls");
    if (i == 1)
        student();
    else
        librarian();
}

void Library::modify()
{
    char ch, str[100];
    int i = 0, types, count = 0;
    system("cls");
    cout << "\n\n\t\t\t\t1-Modify The Books\n\n\t\t\t\t2-Add A Book\n\n\t\t\t\t3-Delete A Book\n\n\t\t\t\t_______________________________\n\n\t\t\t\t4-Back\n\t\t\t\t5-Main menu\n\n";
    cout << "Enter A choice: ";
    cin >> i;
    if (i == 1)
    {
        system("cls");
        types = department(2);
        ifstream iFile("BookList.txt", ios::binary);
        if (!iFile)
        {
            cout << "Sorry, Can't Open That File\n";
            cout << "Press Any Key To Continue. . .\n";
            getch();
            system("cls");
            librarian();
        }
        iFile.close();
        system("cls");
        cout << "\n1-Search on Book By Name\n\n2-Search on Book By ID\nEnter A Choice: ";
        cin >> i;
        fflush(stdin);
        if (i == 1)
        {
            system("cls");
            cout << "Book's Name: ";
            cin.getline(str, 100);
            system("cls");
            fstream File2("BookList.txt", ios::out | ios::in | ios::ate | ios::binary);
            File2.seekg(0);
            File2.read((char *)this, sizeof(*this));
            while (!File2.eof())
            {
                for (i = 0; types == B && book_name[i] != '\0' && str[i] != '\0' && (str[i] == book_name[i] || str[i] == book_name[i] + 32); i++)
                    ;
                if (str[i] == '\0' && book_name[i] == '\0')
                {
                    count++;
                    getdata();
                    File2.seekp(File2.tellp() - sizeof(*this));
                    File2.write((char *)this, sizeof(*this));
                    break;
                }
                File2.read((char *)this, sizeof(*this));
            }
            File2.close();
        }
        else if (i == 2)
        {
            system("cls");
            cout << "Book's ID: ";
            cin.getline(str, 100);
            system("cls");
            fstream File2("BookList.txt", ios::out | ios::in | ios::ate | ios::binary);
            File2.seekg(0);
            File2.read((char *)this, sizeof(*this));
            while (!File2.eof())
            {
                for (i = 0; types == B && str1[i] != '\0' && str[i] != '\0' && str[i] == str1[i]; i++)
                    ;
                if (str[i] == '\0' && str1[i] == '\0')
                {
                    count++;
                    getdata();
                    File2.seekp(File2.tellp() - sizeof(*this));
                    File2.write((char *)this, sizeof(*this));
                    break;
                }
                File2.read((char *)this, sizeof(*this));
            }
            File2.close();
        }
        else
        {
            cout << "\nINVALID INPUT\nPress Any Key To Continue. . .\n";
            getch();
            system("cls");
            modify();
        }
        if (count == 0)
        {
            cout << "\nSorry, Not Found\nPress Any Key To Continue. . .\n";
            getch();
            system("cls");
            modify();
        }
        else
            cout << "\nUpdated Successful\n";
    }
    else if (i == 2)
    {
        system("cls");
        B = department(2);
        system("cls");
        getdata();
        ofstream oFile("BookList.txt", ios::app | ios::binary);
        oFile.write((char *)this, sizeof(*this));
        oFile.close();
        cout << "\nAdded Successful\n";
    }
    else if (i == 3)
    {
        system("cls");
        types = department(2);
        ifstream iFile("BookList.txt", ios::binary);
        if (!iFile)
        {
            cout << "Sorry, Can't Open That File\n";
            cout << "Press Any Key To Continue. . .\n";
            getch();
            iFile.close();
            system("cls");
            librarian();
        }
        iFile.close();
        system("cls");
        cout << "\n1-Search on Book By Name\n\n2-Search on Book By ID\nEnter A Choice: ";
        cin >> i;
        fflush(stdin);
        if (i == 1)
        {
            system("cls");
            cout << "Book's Name: ";
            cin.getline(str, 100);
            ofstream oFile2("tmp.txt", ios::binary | ios::app);
            ifstream iFile2("BookList.txt", ios::binary);
            iFile2.read((char *)this, sizeof(*this));
            while (!iFile2.eof())
            {
                for (i = 0; types == B && book_name[i] != '\0' && str[i] != '\0' && (str[i] == book_name[i] || str[i] == book_name[i] + 32); i++)
                    ;
                if (str[i] == '\0' && book_name[i] == '\0')
                {
                    count++;
                    iFile2.read((char *)this, sizeof(*this));
                }
                else
                {
                    oFile2.write((char *)this, sizeof(*this));
                    iFile2.read((char *)this, sizeof(*this));
                }
            }
            iFile2.close();
            oFile2.close();
            remove("BookList.txt");
            rename("tmp.txt", "BookList.txt");
        }
        else if (i == 2)
        {
            cout << "Book's ID: ";
            cin.getline(str, 100);
            system("cls");
            ofstream oFile2("tmp.txt", ios::binary | ios::app);
            ifstream iFile2("BookList.txt", ios::binary);
            iFile2.read((char *)this, sizeof(*this));
            while (!iFile2.eof())
            {
                for (i = 0; types == B && str1[i] != '\0' && str[i] != '\0' && str[i] == str1[i]; i++)
                    ;
                if (str[i] == '\0' && str1[i] == '\0')
                {
                    count++;
                    iFile2.read((char *)this, sizeof(*this));
                }
                else
                {
                    oFile2.write((char *)this, sizeof(*this));
                    iFile2.read((char *)this, sizeof(*this));
                }
            }
            iFile2.close();
            oFile2.close();
            remove("BookList.txt");
            rename("tmp.txt", "BookList.txt");
        }
        else
        {
            cout << "\nINVALID INPUT\nPress Any Key To Continue. . .\n";
            getch();
            system("cls");
            modify();
        }
        if (count == 0)
        {
            cout << "\nSorry, Not Found\nPress Any Key To Continue. . .\n";
            getch();
            system("cls");
            modify();
        }
        else
            cout << "\nDeleted Successful\n";
    }
    else if (i == 4)
    {
        system("cls");
        librarian();
    }
    else if (i == 5)
    {
        system("cls");
        interface();
    }
    else
    {
        cout << "\nINVALID INPUT\nPress Any Key To Continue. . .\n";
        getch();
        system("cls");
        modify();
    }
    cout << "\nPress Any Key To Continue. . .\n";
    getch();
    system("cls");
    librarian();
}

int Library::department(int x)
{
    int choice;
    cout << "\n\t\t\t---------Departments----------\n";
    cout << "\n\t\t\t1-Biographies & Memoirs\n\t\t\t2-Business & Money\n\t\t\t3-Children's Books\n\t\t\t4-Computers & Technology\n\t\t\t5-Education & Teaching\n\t\t\t6-Engineering & Transportation\n\t\t\t_______________________________\n\n\t\t\t7-Back\n\t\t\t8-Main menu\n";
    cout << "Enter your Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;
    case 3:
        return 3;
        break;
    case 4:
        return 4;
        break;
    case 5:
        return 5;
        break;
    case 6:
        return 6;
        break;
    case 7:
        system("cls");
        if (x == 1)
            student();
        else
            librarian();
    case 8:
        system("cls");
        interface();
    default:
        cout << "Wrong INPUT, please Enter The Correct Choice\n";
        getch();
        system("cls");
        department(x);
    }
}
void Library::search(int x)
{
    int count = 0, i, types;
    char ch[100];
    system("cls");
    types = department(x);
    ifstream iFile("BookList.txt", ios::binary);
    if (!iFile)
    {
        cout << "Sorry, Can't Open That File\n";
        cout << "Press Any Key To Continue. . .\n";
        getch();
        system("cls");
        if (x == 1)
            student();
        else
            librarian();
    }
    system("cls");
    cout << "\n1-Search on Book By Name\n\n2-Search on Book By ID\nEnter A Choice: ";
    cin >> i;
    fflush(stdin);
    iFile.read((char *)this, sizeof(*this));
    if (i == 1)
    {
        system("cls");
        cout << "Book's Name: ";
        cin.getline(ch, 100);
        system("cls");
        iFile.read((char *)this, sizeof(*this));
        while (!iFile.eof())
        {
            for (i = 0; types == B && qua != 0 && book_name[i] != '\0' && ch[i] != '\0' && (ch[i] == book_name[i] || ch[i] == book_name[i] + 32); i++)
                ;
            if (ch[i] == '\0' && book_name[i] == '\0')
            {
                count++;
                cout << "\n\t\tFound:\n";
                display(x);
                break;
            }
            iFile.read((char *)this, sizeof(*this));
        }
    }
    else if (i == 2)
    {
        cout << "Book's ID: ";
        cin.getline(ch, 100);
        system("cls");
        iFile.read((char *)this, sizeof(*this));
        while (!iFile.eof())
        {
            for (i = 0; types == B && qua != 0 && str1[i] != '\0' && ch[i] != '\0' && ch[i] == str1[i]; i++)
                ;
            if (ch[i] == '\0' && str1[i] == '\0')
            {
                count++;
                cout << "\n\t\tFound:\n";
                display(x);
                break;
            }
            iFile.read((char *)this, sizeof(*this));
        }
    }
    else
    {
        cout << "\nINVALID INPUT\nPress Any Key To Continue. . .\n";
        getch();
        system("cls");
        search(x);
    }
    iFile.close();
    if (count == 0)
        cout << "\nSorry, This Book is NOT Available now try later, Thank You\n";

    cout << "Press Any Key To Continue. . .\n";
    getch();
    system("cls");
    if (x == 1)
        student();
    else
        librarian();
}
void Library::issue()
{
    char st[50], st1[20];
    int b, i, j, d, m, y, dd, mm, yy, count = 0;
    system("cls");
    cout << "\n\n\t\t\t________________ Welcome ^_^ __________________\n";
    cout << "\n\n\t\t\t\t\t1-Issue a Book\n\n\t\t\t\t\t2-List Of Issued Books\n\n\t\t\t\t\t3-Search on Students who Issued Books\n\n\t\t\t\t\t4-Reissue a Book\n\n\t\t\t\t\t5-Return a Book\n\t\t\t\t______________________________\n\n\n\t\t\t\t\t6-Back\n\n\t\t\t\t\t7-Main Menu\n\nEnter A Choice: ";
    cin >> i;
    fflush(stdin);
    if (i == 1)
    {
        system("cls");
        b = department(2);
        system("cls");
        fflush(stdin);
        cout << "\n\n\t\t\tEnter the Details:\n\n";
        cout << "\n\t\t\tBook's Name: ";
        cin.getline(book_name, 100);
        cout << "\n\t\t\tBook's ID: ";
        cin.getline(str1, 20);
        der(str1, b, 1);
        cout << "\n\t\t\tStudent's Name: ";
        cin.getline(author_name, 100);
        cout << "Student's ID: ";
        cin.getline(str2, 20);
        cout << "\n\t\t\tEnter A Data: ";
        cin >> qua >> B >> pri;
        ofstream oFile("student.txt", ios::binary | ios::app);
        oFile.write((char *)this, sizeof(*this));
        oFile.close();
        cout << "\n\n\t\tIssued Successfully.\n";
    }
    else if (i == 2)
    {
        ifstream iFile("student.txt", ios::binary);
        system("cls");
        cout << "\n\n\t\t\tList Of Issued Books:\n\n";
        iFile.read((char *)this, sizeof(*this));
        i = 0;
        while (!iFile.eof())
        {
            i++;
            cout << "\n\t\t\t********** " << i << ". ********** \n";
            cout << "\n\t\tStudent Name : " << author_name << "\n\t\t\t"
                 << "Student's ID : " << str2 << "\n\t\t\t"
                 << "Book Name : " << book_name << "\n\t\t\t"
                 << "Book's ID : " << str1 << "\n\t\t\t"
                 << "Date : " << qua << "/" << B << "/" << pri << "\n";
            iFile.read((char *)this, sizeof(*this));
        }
        iFile.close();
    }
    else if (i == 3)
    {
        system("cls");
        fflush(stdin);
        cout << "\n\t\t\tEnter The info:\n";
        cout << "\n\t\t\tStudent's Name: ";
        cin.getline(st, 50);
        cout << "\n\t\t\tStudent's ID: ";
        cin.getline(st1, 20);
        system("cls");
        ifstream iFile("student.txt", ios::binary);
        /*
        if (!File)
        {
            cout << "Sorry, Can't Open That File\n";
            cout << "Press Any Key To Continue. . .\n";
            getch();
            system("cls");
            librarian();
        }
        */
        iFile.read((char *)this, sizeof(*this));
        count = 0;
        while (!iFile.eof())
        {
            for (i = 0; str1[i] != '\0' && st1[i] != '\0' && st1[i] == str1[i]; i++)
                ;
            if (str1[i] == '\0' && st1[i] == '\0')
            {

                count++;
                if (count == 1)
                {
                    cout << "\n\t\t\tINFO:\n";
                    cout << "\n\t\t\tStudent's Name: " << author_name;
                    cout << "\n\t\t\tStudent's ID: " << str2;
                }
                cout << "\n\n\t\t________ " << count << " _______n";
                cout << "\n\t\t\tBook's Name: " << book_name;
                cout << "\n\t\t\tBook's ID: " << str1;
                cout << "\n\t\tDate : " << qua << "/" << B << "/" << pri << "\n";
            }
            iFile.read((char *)this, sizeof(*this));
        }
        iFile.close();
        if (count == 0)
            cout << "\n\t\tNo record found.";
    }
    else if (i == 4)
    {
        system("cls");
        fflush(stdin);
        cout << "\n\t\t\tEnter Info:\n";
        cout << "\n\t\t\tStudent's ID: ";
        cin.getline(st, 50);
        cout << "\n\t\t\tBook's ID: ";
        cin.getline(st1, 20);
        fstream File("student.txt", ios::in | ios::out | ios::ate | ios::binary);
        /*
        if (!File)
        {
            cout << "Sorry, Can't Open That File\n";
            cout << "Press Any Key To Continue. . .\n";
            getch();
            system("cls");
            librarian();
        }
        */
        File.seekg(0);
        File.read((char *)this, sizeof(*this));
        while (!File.eof())
        {
            for (i = 0; str1[i] != '\0' && st1[i] != '\0' && st1[i] == str1[i]; i++)
                ;
            for (j = 0; str2[j] != '\0' && st[j] != '\0' && st[j] == str2[j]; j++)
                ;
            if (str1[i] == '\0' && str2[j] == '\0' && st[j] == '\0' && st1[i] == '\0')
            {
                d = qua;
                m = B;
                y = pri;
                cout << "\n\n\n\t\t\tEnter Your NEW DATE: ";
                cin >> qua >> B >> pri;
                fine(d, m, y, qua, B, pri);
                File.seekp(File.tellp() - sizeof(*this));
                File.write((char *)this, sizeof(*this));
                cout << "\n\n\t\tReissue Successfully.";
                break;
            }
            File.read((char *)this, sizeof(*this));
        }
        File.close();
    }
    else if (i == 5)
    {
        system("cls");
        b = department(2);
        system("cls");
        cout << "\n\n\t\t\t\tENTER INFO:\n";
        cout << "\n\n\t\t\t\tBook's ID: ";
        cin.getline(st1, 20);
        der(st1, b, 2);
        cout << "\n\n\t\t\t\tStudent's ID: ";
        cin.getline(st, 20);
        cout << "\n\n\n\t\t\t\tEnter DAY DATE: ";
        cin >> d >> m >> y;
        ofstream oFile("tmp.txt", ios::binary | ios::app);
        ifstream iFile("student.txt", ios::binary);
        /*
        if (!iFile)
        {
            cout << "Sorry, Can't Open That File\n";
            cout << "Press Any Key To Continue. . .\n";
            getch();
            system("cls");
            librarian();
        }
        */
        iFile.read((char *)this, sizeof(*this));
        while (!iFile.eof())
        {
            for (i = 0; str1[i] != '\0' && st1[i] != '\0' && st1[i] == str1[i]; i++)
                ;
            for (j = 0; str2[j] != '\0' && st[j] != '\0' && st[j] == str2[j]; j++)
                ;
            if (str1[i] == '\0' && str2[j] == '\0' && st[j] == '\0' && st1[i] == '\0' && count == 0)
            {
                count++;
                iFile.read((char *)this, sizeof(*this));
                fine(qua, B, pri, d, m, y);
                cout << "Returned Successfully\n";
            }
            else
            {
                oFile.write((char *)this, sizeof(*this));
                iFile.read((char *)this, sizeof(*this));
            }
        }
        iFile.close();
        oFile.close();
        getch();
        remove("student.txt");
        rename("tmp.txt", "student.txt");
    }
    else if (i == 6)
    {
        system("cls");
        librarian();
    }
    else if (i == 7)
    {
        system("cls");
        interface();
    }
}
void Library::fine(int d, int m, int y, int dd, int mm, int yy)
{
    long int n1, n2;
    int years, l, i;
    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    n1 = y * 365 + d;
    for (i = 0; i < m - 1; i++)
        n1 += monthDays[i];
    years = y;
    if (m <= 2)
        years--;
    l = years / 4 - years / 100 + years / 400;
    n1 += l;
    n2 = yy * 365 + dd;
    for (i = 0; i < mm - 1; i++)
        n2 += monthDays[i];
    years = yy;
    if (m <= 2)
        years--;
    l = years / 4 - years / 100 + years / 400;
    n2 += l;
    n1 = n2 - n1;
    n2 = n1 - 15;
    if (n2 > 0)
        cout << "\n\t\tThe Total Fine is : " << n2;
}

void Library::der(char st[], int b, int x)
{
    int i, count = 0;
    fstream File("BookList.txt", ios::in | ios::out | ios::ate | ios::binary);
    File.seekg(0);
    File.read((char *)this, sizeof(*this));
    while (!File.eof())
    {
        for (i = 0; b == B && str1[i] != '\0' && st[i] != '\0' && st[i] == str1[i]; i++)
            ;
        if (str1[i] == '\0' && st[i] == '\0')
        {
            count++;
            if (x == 1)
                qua--;
            else
                qua++;
            File.seekp(File.tellp() - sizeof(*this));
            File.write((char *)this, sizeof(*this));
            break;
        }
        File.read((char *)this, sizeof(*this));
    }
    if (count == 0)
    {
        cout << "\n\t\tNOT Found.\n";
        cout << "\n\n\t\tPress Any Key To Continue.....";
        getch();
        system("cls");
        issue();
    }
    File.close();
}
void Library::librarian()
{
    int choice;
    cout << "\n\n\t\t\t\t ___________ LIBRARIAN _________\n";
    cout << "\n\n\t\t\t\t1-View BookList\n\n\t\t\t\t2-Search for a Book\n\n\t\t\t\t3-Modify/Add Book\n\n\t\t\t\t4-Issue Book\n\n\t\t\t\t5-Change Password\n\n\t\t\t\t_______________________\n\n\t\t\t\t6-Main Menu\n\n\t\t\t\t7-Close Application\n";
    cout << "\n\t\tEnter Your Chioce : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        booklist(2);
        break;
    case 2:
        search(2);
        break;
    case 3:
        modify();
        break;
    case 4:
        issue();
        break;
    case 5:
        system("cls");
        new_password();
        break;
    case 6:
        system("cls");
        interface();
        break;
    case 7:
        exit(0);
    default:
        cout << "\n\n\t\tINVALID CHOICE";
        cout << "\n\n\t\tPress Any Key To Continue. . .";
        getch();
        system("cls");
        librarian();
    }
}
void Library::interface()
{
    int choice;
    cout << "\n\n\t\t\t\t___________ WELCOME ^o^ ____________\n\n";
    cout << "\n\t\t\t\t1- Student.\n\n\t\t\t\t2- Librarian.\n\n\t\t\t\t3- Exit.\n\n";
    cout << "Choose an Option: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        student();
        break;
    case 2:
        check_pass();
        break;
    case 3:
        exit(0);
    default:
        cout << "INVALID OPTION\n\n(1-3) are ONLY available\n";
        cout << "\n\n\t\tPress Any Key To Continue. . .";
        getch();
        interface();
        break;
    }
}
void Library::student()
{
    int choice;
    cout << "\n\n\t\t\t\t___________ WELCOME Student ^o^ ____________\n\n";
    cout << "\n\n\t\t\t\t1- Book List\n\n\t\t\t\t2- Search on Books\n\n\t\t\t\t3- Main Menu\n\nChoose an option: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        booklist(1);
        break;
    case 2:

        search(1);
    case 3:
        system("cls");
        interface();
    default:
        cout << "\n\nINVALID OPTION\n\n(1-3) are ONLY Available\n";
        cout << "\n\n\t\tPress Any Key To Continue. . .";
        getch();
        student();
        break;
    }
}
void Library::new_password()
{
    string pass2;
    ifstream iFile("pass.txt");
    iFile >> pass2;

    ofstream oFile("pass.txt");
    system("cls");
    cout << "\n\t\t\t\t----MIN 6 OR MAX 15  Digits OR Charachters-----\n";
    cout << "\n\n\n\t\t\t\tEnter a New Password  : ";
    string pass;
    int i = 0, ch;
    char a;
    for (i = 0;;)
    {
        a = getch();
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || (a == '@'))
        {
            pass += a;
            ++i;
            cout << "*";
        }
        if (a == '\b' && i >= 1)
        {
            cout << "\b \b";
            --i;
        }
        if (a == '\r')
        {
            pass[i] = '\0';
            break;
        }
    }
    if (i <= 5 || i >= 19)
    {
        system("cls");
        cout << "\nMIN 6 OR MAX 15  Digits OR Charachters are ONLY Allowed.\n\nEnter 1 to try again or you can go back to menu by Enter 2\n\nEnter: ";
        cin >> ch;
        fflush(stdin);
        while (ch != 1 && ch != 2)
        {
            cout << "Enter only 1 or 2: ";
            cin >> ch;
        }
        if (ch == 1)
            new_password();
        else
            librarian();
    }
    else if (pass == pass2)
    {
        char check;
        cout << "This New a Password has been enterd already!!\n\nDo you Want to Confirm it? yes(y) / no(n): ";
        cin >> check;
        if (check == 'y')
        {
            oFile << pass;
            oFile.close();
            cout << "Updated Successfuly\n";
            cout << "\n\n\t\tPress Any Key To Continue. . .";
            getch();
            system("cls");
            librarian();
        }
        else
        {
            cout << "Enter 1 to try again or you can go back to menu by Enter 2\n\nEnter: ";
            cin >> ch;
            fflush(stdin);
            while (ch != 1 && ch != 2)
            {
                cout << "\n\nEnter Only 1 or 2: ";
                cin >> ch;
            }
            if (ch == 1)
                new_password();
            else
                librarian();
        }
    }
    else
    {
        oFile << pass;
        oFile.close();
        cout << "\n\n\t\tUpdated Successfuly\n";
        cout << "\n\n\t\tPress Any Key To Continue. . .";
        getch();
        system("cls");
        librarian();
    }
}
void Library::check_pass()
{
    system("cls");
    string pass2;
    ifstream iFile("pass.txt");
    iFile >> pass2;

    string pass;
    ifstream("pass.txt");
    cout << "\n\n\t\t\t\tEnter a Password: ";
    int i = 0;
    char a;
    for (i = 0;;)
    {
        a = getch();
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || (a == '@'))
        {
            pass += a;
            ++i;
            cout << "*";
        }
        if (a == '\b' && i >= 1)
        {
            cout << "\b \b";
            --i;
        }
        if (a == '\r')
        {
            pass[i] = '\0';
            break;
        }
    }
    if (pass == pass2)
    {
        //cout << "\n\n\t\t\t\t login Successfully\n";
        system("cls");
        librarian();
    }
    else
    {
        cout << "\n\n\t\t\t\tWrong Password\n";
        cout << "\n\n\t\tPress Any Key To Continue. . .";
        getch();
        system("cls");
        interface();
    }
}

int main()
{
    //Library obj;
    //obj.interface();
    Adress ad;
    //ad.dis_ad();
    ifstream iFile("shippingAddresses.dat", ios::binary);
    while (iFile.read((char *)&ad, sizeof(Adress)))
    {
        ad.display_adress();
    }
    iFile.close();
    //adress();
    getch();
    return 0;
}