#include <iostream>
#include <string>

using namespace std;

namespace View
{
    class UI
    {
    public:
        void prompt(string s)
        {
            cout << s;
        }

        void prompt(int i)
        {
            cout << i;
        }

        int getInput()
        {
            int x;
            cin >> x;
            return x;
        }
    };
};
namespace Model
{
    class Storage
    {
    private:
        int x;
    public:
        void store(int n)
        {
            x = n;
        }
        int retrieve()
        {
            return x;
        }
    };
};
namespace Controller
{
    class Logic
    {
        View::UI* u;
        Model::Storage* s;
    public:
        Logic(View::UI* _u, Model::Storage* _s)
        {
            u = _u;
            s = _s;

            doLogic();
        }
        void doLogic()
        {
            // ask there user for a number using the UI object (View)
            u->prompt("Enter a number: ");
            int i = u->getInput();

            // store that number in the Storage object (Model)
            s->store(i);

            // retrieve that number from the Storage object (Model)
            int x = s->retrieve();

            // display that to the user using the UI object (View)
            u->prompt("Here is the number you entered: ");
            u->prompt(x);
            u->prompt("\n");
        }
    };
};




int main()
{
    View::UI u;
    Model::Storage s;

    Controller::Logic l(&u, &s);

    return 0;
}
