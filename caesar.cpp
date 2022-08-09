#include <iostream>
#include <fstream>

class Caesar
{
public:
    Caesar();
    ~Caesar();
public:
    void setKey(int);
    int getKey() const;
    void encrypt();
    void decrypt();
private:
    int _key;
    std::fstream fin;
    std::fstream fout;
};

Caesar::Caesar()
{
    std::string str1 = "encode.txt";
    std::string str2 = "decode.txt";
    fin.open(str1);
    fout.open(str2);
    if (fin.is_open() && fout.is_open())
    {
        std::cout << "Files are open." << std::endl;
    }
    else
    {
        std::cout << "Can't open the files.";
    }
}

Caesar::~Caesar()
{
    fin.close();
    fout.close();
}

void Caesar::setKey(int key)
{
    _key = key;
}

int Caesar::getKey() const
{
    return _key;
}

void Caesar::encrypt()
{
    std::string str = "";
    while (!fin.eof())
    {
        std::string tmp = "";
        std::getline(fin, tmp);
        for (int i = 0; i < tmp.size(); ++i)
        {
            if (tmp[i] >= 'A' && tmp[i] <= 'Z')
            {
                if ((tmp[i] - _key) < 'A')
                {
                    str += char((tmp[i] - _key) + 26);
                }
                else
                {
                    str += char(tmp[i] - _key);
                }
            }
            else if (tmp[i] >= 'a' && tmp[i] <= 'z')
            {
                if ((tmp[i] - _key) < 'a')
                {
                    str += char((tmp[i] - _key) + 26);
                }
                else
                {
                    str += char(tmp[i] - _key);
                }
            }
            else
            {
                str += char(tmp[i]);
            }
            fout << str;
            str = "";
        }
    }
}

void Caesar::decrypt()
{
    std::string str = "";
    while (!fout.eof())
    {
        std::string tmp = "";
        std::getline(fout, tmp);
        for (int i = 0; i < tmp.size(); ++i)
        {
            if (tmp[i] >= 'A' && tmp[i] <= 'Z')
            {
                if ((tmp[i] - _key) > 'Z')
                {
                    str += char((tmp[i] + _key) - 26);
                }
                else
                {
                    str += char(tmp[i] + _key);
                }
            }
            else if (tmp[i] >= 'a' && tmp[i] <= 'z')
            {
                if ((tmp[i] + _key) > 'z')
                {
                    str += char((tmp[i] + _key) - 26);
                }
                else
                {
                    str += char(tmp[i] + _key);
                }
            }
            else
            {
                str += tmp[i];
            }
            fin << str;
            str = "";
        }
    }
}

int main()
{
    Caesar obj;
    int key;
    obj.setKey(3);
    obj.encrypt();
    //obj.decrypt();
}