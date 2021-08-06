/*
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <conio.h>
using namespace std;


class Adress
{
public:
    char area[50], first_name[20], last_name[20], governorate[30], city[20], street_name[100], mobile[20], building_name[20], floor_no[10], apartment_no[5], nearest_landmark[50];
    void dis_ad();
    void display_adress();
    void get_adress();
    //void proceed_checkout();
};
void adress();
//void proceed_checkout();

void Adress::get_adress()
{
    fflush(stdin);
    cout << "\n\n\t\t\tMy Address:-\n\n\t\t\tFirst Name: ";
    cin.getline(first_name, 20);
    cout << "\n\t\t\tLast Name: ";
    cin.getline(last_name, 20);
    cout << "\n\t\t\tGovernorate: ";
    cin.getline(governorate, 30);
    cout << "\n\t\t\tCity: ";
    cin.getline(city, 20);
    cout << "\n\t\t\tArea: ";
    cin.getline(area, 50);
    cout << "\n\t\t\tStreet Name/NO. : ";
    cin.getline(street_name, 100);
    cout << "\n\t\t\tMobile: ";
    cin.getline(mobile, 20);
    cout << "\n\n\t\t\tBuilding Name/No. : ";
    cin.getline(building_name, 20);
    cout << "\n\t\t\tFloor No. : ";
    cin.getline(floor_no, 10);
    cout << "\n\t\t\tApartment No. : ";
    cin.getline(apartment_no, 5);
    cout << "\n\t\t\tNearest Landmark: ";
    cin.getline(nearest_landmark, 50);
}
/*
void Adress::proceed_checkout()
{
    //Adress ad;
    ofstream oFile("shipping addresses.dat", ios::binary | ios::app);
    get_adress();
    oFile.write((char *)this, sizeof(*this));
    oFile.close();
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
    cout << "\n\n\t\t\tBuilding Name/No. : " << building_name;
    cout << "\n\n\t\t\tFloor No. : " << floor_no;
    cout << "\n\n\t\t\tApartment No. : " << apartment_no;
    cout << "\n\n\t\t\tNearest Landmark: " << nearest_landmark;
}
void Adress::dis_ad()
{
    ifstream iFile("shippingAddresses.dat", ios::binary);
    while (!iFile.read((char *)this, sizeof(*this)))
    {
        display_adress();
        break;
    }
    iFile.close();
}
void adress()
{
    Adress ad;
    ad.dis_ad();
}
int main()
{
    Adress ad;    
    //ad.dis_ad();
    //ad.proceed_checkout();
    adress();
}
*/
#include <iostream>
    #include <stdio.h>
    #include <stdlib.h>
    #include <fstream>
    #include <string.h>
    #include <conio.h>
    using namespace std;
    
    
    class Adress
    {
    public:
        char area[50], first_name[20], last_name[20], governorate[30], city[20], street_name[100], mobile[15], building_name[20], floor_no[10], apartment_no[5], nearest_landmark[50];
        void dis_ad();
        void display_adress();
        void get_adress();
    };
    
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
    int main()
    {
        Adress ad;
        //ad.get_adress();
        ad.dis_ad();
    }





/*
     My Address:-

                        First Name: John


                        Last Name: Mike


                        Governorate: Gize


                        City: 6 October


                        Area: 4th District


                        Street Name/NO. : Conrad, 42, Washington, D.C.


                        Mobile: 123456789



                        Building Name/No. : 833


                        Floor No. : 3


                        Apartment No. : 7


                        Nearest Landmark: Pharmacy
                        */