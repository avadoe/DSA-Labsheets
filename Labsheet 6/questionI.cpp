#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
A VALID PATH
    •Starts with ‘/’
    •The path may contain directories, period ‘.’ or double period ‘.’.
    •Any two directories are separated by a slash ’/’ (single or multiple).
    •The path will not have whitespace characters.
*/

/*
IN A PATH
    •A period ‘.’ refers to the current directory.
    •A double period ‘..’ refers to the directory one level up.
    •Any multiple consecutive slashes ‘//’ are treated as a single slash ‘/’.
*/

int main()
{
    string path;
    getline(cin, path);

    stack<string> st;

    int i = 0;
    while (i < path.size()) {
        // Skip any leading slashes

        while (i < path.size() && path[i] == '/') {
            i++;
        }

        // Get the next directory name
        string temp = "";
        while (i < path.size() && path[i] != '/') {
            temp += path[i];
            i++;
        }

        if (temp == "..") {
            if (!st.empty()) {
                st.pop();
            }
        } else if (temp != ".") {
            st.push(temp);
        }
    }

    // Reconstruct the simplified path
    string ans = "/";
    while (!st.empty()) {
        ans = "/" + st.top() + ans;
        st.pop();
    }

    if(ans.length() > 1){
        ans = ans.substr(0, ans.length() - 2);
    }

    cout << ans << endl;

    return 0;
}
