//A program that programatically converts from decimal to binary and then back.
//Made by Lawrence Warren, 04/08/2019. My first C++ program! (Not Hello World)

//Libraries
#include <iostream> //For input output (cin >> , cout <<)
#include <string>   //Allows for more string related functions.
#include <sstream>  //String stream (library function for converting string to int)

std::string toBinary(std::string i) //Convert to binary.
{
    //Declaring variables
    bool x = false;
    std::string final;
    int val;
    std::stringstream convert(i);
    convert >> val; //streams the value of 'convert' onto 'val'

    while (x==false)
    {
        if (val==1)
        {
            x=true;
        }

        final.insert(0, std::to_string(val%2)); //converts val%2 to a string, prepends 'final'

        val/=2; //Divides and set's value.
    }

    return final;
}

std::string fromBinary(std::string val) //Convert from binary.
{
    int final=0, temp=0, counter=1;
    bool x = false;

    while (x==false)
    {
        temp = val.back() - '0';    //ASCII value of val.back minus ASCII value of 0.
        final += (temp *= counter); //Final incremented each loop by temp*counter.
        val.pop_back();
        counter*=2;

        if (val == "") { x=true; }
    }

    return std::to_string(final);
}

int checkBinary(std::string val)
{
    bool x = false;

    while(x==false)
    {
        if(val.back()=='1'||val.back()=='0')
        {
            val.pop_back();
            if(val=="") { x=true;}
        }
        
        else
        {
            std::cout << "Please use a binary number for this mode!";
            return 1;
        }
    }
    return 0;
}

int checkDec(std::string val)
{
    bool x = false;

    while(x==false)
    {
        if(val.back()=='0'||val.back()=='1'||val.back()=='2'||val.back()=='3'||val.back()=='4'||val.back()=='5'||val.back()=='6'||val.back()=='7'||val.back()=='8'||val.back()=='9')
        {
            val.pop_back();
            if(val=="") { x=true;}
        }
        
        else
        {
            std::cout << "Please use a decimal number for this mode!";
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Provide more arguments!";
        return 1;
    }

    //Declare variables
    std::string converted;
    std::stringstream convert(argv[2]);
    int val;
    convert >> val;

    if (std::string(argv[1])=="f" || std::string(argv[1])=="F")
    {
        if(checkBinary(argv[2])!=0)  { return 1; }
        converted = fromBinary(argv[2]);
    }

    else if(std::string(argv[1])=="t" || std::string(argv[1])=="T")
    {
        if(checkDec(argv[2])!=0)  { return 1; }
        converted = toBinary(argv[2]);
    }

    else
    {
        std::cout << "Provide correct modes, [F] or [T]!";
        return 1;
    }

    std::cout << "Your value " << val << " has been converted to " << converted;
    return 0;
}