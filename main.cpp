#include <fstream>
#include <map>
#include <cstring>
#include "graphs.h"
#include "customers.h"
#include "admin.h"
#include <cstdlib>
using namespace std;

//global variables
Admin Ad[3];
Agent Ag[15];
map <string, int> m;
Trie CT;

void enter(); //forward declaration 

void initLocations(){
    string locations[50] = {
        "Delhi", "Mumbai", "Hongkong", "Tokyo", "Bangkok", "Singapore", "Sydney", "Melbourne",
        "Dubai", "Cairo", "Moscow", "Stockholm", "Seoul", "Canada", "Shanghai", "Beijing", "San Francisco",
        "Washington DC", "Los Angeles", "Chicago", "New York", "South Africa", "Rio", "Santiago", "Mexico",
        "Peru", "Miami", "London", "Germany", "Italy", "Paris"
    };
    for(int i=0; locations[i]!=""; i++){
        m[locations[i]] = 1;
    }
    cout<<"Initiated locations map\n";
}

//Admin Portal
void visit_admin_portal(){
    //create login fn
    bool success = login_admin(Ad,2);
    if(success){
        system("clear");
        cout<<"WELCOME TO ADMIN PORTAL\n";
        int x;
        cout<<"1: Edit the Locations\n";
        cout<<"2: Update list of Agents\n";
        cout<<"3: View all Customers\n";
        cout<<"4: View all Bookings\n";
        cout<<"5: Navigate back\n";
        cout<<"6: Exit\n";
        cin>>x;
        switch(x){
            case 3: {
                system("clear");
                view_all_customers();
                cout<<"Press any key, followed by 'enter' key, to navigate back.\n";
                char c;
                cin>>c;
                //FIX THIS FLOW OF FN CALL & FLOW OF EXECUTION
                //FIX PASSING OF CONTROL TO LOGIN FN, THE SECOND TIME USER VISITS ADMIN PORTAL
                //visit_admin_portal();
                break;
            }
            case 6: {
                system("clear");
                cout<<"Thank you for using the Travel Plan Management Software!\n";
                cout<<"Built by ABHILASHA BANSAL & ABHAY GUPTA\n";
                cout<<"Exitting now ...\n";
                break;
            }
            default: {
                cout<<"Invalid Input\n";
                visit_admin_portal();
            }
        }
        
    }
    else{
        cout<<"Login failed, please enter correct details again.\n";
        cout<<"Press any key, followed by 'enter' key, to navigate back.\n";
        char c;
        cin>>c;
        visit_admin_portal();
    }
    cout<<"This portal is still under development.\n";
}

//Customer Portal
void visit_customer_portal(){
    system("clear");
    int x;
    cout<<"1: Create an account\n";
    cout<<"2: View all locations\n";
    cout<<"3: Find a Plan\n";
    cout<<"4: View your Bookings\n";
    cout<<"5: Navigate back\n";
    cout<<"6: Exit\n";
    cin>>x;
    switch(x){
        case 1: {
            bool p = createAccount(CT);
            visit_customer_portal();
            break;
        }
        case 2: {
            system("clear");
            cout<<"AVAILABLE LOCATIONS\n";
            for(auto p: m){
                cout<<p.first<<endl;
            }
            char x;
            cout<<"Press any key, followed by 'enter' key, to navigate back.\n";
            cin>>x;
            cin.clear();
            fflush(stdin);
            visit_customer_portal();
            break;
        }
        case 3: {
            break;
        }
        case 4: {
            break;
        }
        case 5: {
            enter();
            break;
        }
        case 6: {
            system("clear");
            cout<<"Thank you for using the Travel Plan Management Software!\n";
            cout<<"Built by ABHILASHA BANSAL & ABHAY GUPTA\n";
            cout<<"Exitting now ...\n";
            break;
        }
        default: {
            cout<<"Invalid Input\n";
            visit_customer_portal();
        }
    }
}

//Entry Point
void enter(){
    int a;
    system("clear");
    cout<<"1: Go to Admin Portal\n";
    cout<<"2: Go to User Portal\n";
    cout<<"3: Exit\n";
    cin>>a;
    switch(a){
        case 1: {
            visit_admin_portal();
            break; 
        }
        case 2: {
            visit_customer_portal();
            break;
        }
        case 3: {
            system("clear");
            cout<<"Thank you for using the Travel Plan Management Software!\n";
            cout<<"Built by ABHILASHA BANSAL & ABHAY GUPTA\n";
            cout<<"Exitting now ...\n";
            break;
        }
        default: {
            cout<<"Invalid Input\n";
            enter();
        }
    }
}

int main(){
    
    //initialising admins
    initAdmins(Ad);

    int agent_count;
    //initialising travel agents
    initAgents(Ag, agent_count);
    cout<<agent_count<<" agents found!\n";
    cout<<Ag[0].name<<endl;

    //initialising available travel locations
    initLocations();
    for(auto p: m){
        cout<<p.first<<" ";
    }
    cout<<endl;

    cout<<&(CT)<<endl;
    //initialisng customers
    initCustomers(CT);

    char x;
    cout<<"Press any key, followed by 'enter' key, to start program.\n";
    cin>>x;
    cin.clear();
    fflush(stdin);
    enter();
    
    //add more code
    return 0;
}