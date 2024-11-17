#include <iostream>
#include <string>

using namespace std;

const static int ALPHA_LENGTH = 26;
const static int UPPER_LOWER_GAP = 32;

const int cntSpaceIndex(const string& s1, int length)
{   
    int cnt = 0;

    for ( cnt = 0; cnt < length && s1[cnt] == ' '; cnt ++);
    
    return cnt;
}

string setStringLower(const string& s1, int length)
{   
    string res;

    for ( int i = 0; i < length; i ++ )
    {
        if ( isupper(s1[i]) )
            res += char(s1[i] + UPPER_LOWER_GAP);
        else 
            res += char(s1[i]);
    }

    return res;
}

void cntStringNprint(const string& s1, int length)
{
    string res = setStringLower(s1, length);

    int cnt[ALPHA_LENGTH] = {0, };

    for ( int i = 0; i < length; i ++ )
    {   
        if ( isalpha(res[i]) )
            cnt[res[i] - 'a']++;
    }

    for ( int i = 0; i < ALPHA_LENGTH; i ++ )
    {   
        if ( cnt[i] > 0 )
        {   
            char ch = i + 'a';
            cout << "[" << ch << ":" << cnt[i] << "] ";
        }
    }
    cout << endl;
}

const string setString1stUpper(const string& s1, int length)
{
    int index = cntSpaceIndex(s1, length);
    string res = setStringLower(s1, length);
    
    if ( isalpha(res[index]) )
        res[index] = res[index] - UPPER_LOWER_GAP;

    return res;
}  

const string setStringEncode(const string& s1, int length, int gap)
{
    int index = cntSpaceIndex(s1, length);
    string res;

    for ( int i = 0; i < length; i ++ )
    {
        int temp = s1[i] + gap;
        if ( isalpha(s1[i]) )
        {   
            if ( isupper(s1[i]) )
            {
                if ( temp < 'A' )
                    temp += ALPHA_LENGTH;
                else if ( temp > 'Z' )
                    temp -= ALPHA_LENGTH;
            }
            else
            {
                if ( temp < 'a')
                    temp += ALPHA_LENGTH;
                else if ( temp > 'z' )
                    temp -= ALPHA_LENGTH;
            }
        }
        else if ( isdigit(s1[i]) )
        {
            if ( temp < '0' )
                while ( '0' > temp || temp > '9')
                    temp += 10;
            else if ( temp > '9')
                while ( '0' > temp || temp > '9')
                    temp -= 10;
        }
        else 
            temp -= gap;

        res += char(temp);
    }

    return res;
}

int main()
{
    string ent, res;
    int entlength = 0;
    int gap = 0;

    cout << "Input : ";
    getline(cin, ent);
    entlength = ent.length();

    cout << "Gap length : ";
    cin >> gap;

    cntStringNprint(ent, entlength);

    res = setString1stUpper(ent, entlength);
    cout << "Corrected sentence ==> " << res << endl;

    res = setStringEncode(ent, entlength, gap);
    cout << "  Encoded sentence ==> " << res << endl;
}