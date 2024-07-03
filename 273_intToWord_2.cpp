#include <iostream>
#include <string>

using namespace std;

string oneDigit(int num)
{
    // cout << "1 digits: " << num << endl;

    string units[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    // string unit =
    // // cout << unit << endl;
    // result += unit;

    return units[int(num % 10)];
}

string twoDigits(int num)
{
    string result = ""; // String to store the converted word(s)

    if (num < 10 and num >= 0)
    {
        result = oneDigit(int(num % 10));
    }

    if (num < 20 and num >= 10)
    {
        string teens[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        result = teens[int(num % 10)];
    }

    if (num < 100 and num >= 20)
    {
        string tens[10] = {" ", " ", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string unit = oneDigit(int(num % 10));
        string teen = tens[int(num / 10)];
        unit = (unit == "Zero") ? "" : " " + unit;

        result = teen + "" + unit;
    }

    return result;
}

string threeDigits(int num)
{
    string hundred = oneDigit(num / 100);
    hundred = (hundred == "Zero") ? "" : hundred + " Hundred ";
    string nonhundred = twoDigits(num % 100);
    nonhundred = (nonhundred == "Zero") ? "" : nonhundred;

    return "" + hundred + nonhundred;
}

string fourDigits(int num)
{
    string thousand = oneDigit(int(num / 1000));
    thousand = (thousand == "") ? "" : thousand + " Thousand ";
    return "" + thousand + threeDigits(num % 1000);
}

string fiveDigits(int num) // 12345

{
    int thousand = int(num / 1000);
    return "" + twoDigits(thousand) + " Thousand " + threeDigits(int(num % 1000));
}

string sixDigits(int num)
{
    int nonmillion = num % 1000;

    string thousand = threeDigits(int(num / 1000));
    thousand = (thousand == "Zero") ? "" : thousand + " Thousand ";
    return "" +
           thousand + threeDigits(int(num % 1000));
}

string sevenDigits(int num)

{
    int nonmillion = num % 1000000;
    string million = oneDigit(int(num / 1000000));
    million = (million == "") ? "" : million + " Million ";
    return "" + million + sixDigits(nonmillion);
}

string eightDigits(int num)

{
    int nonmillion = num % 1000000;
    string million = twoDigits(int(num / 1000000));
    million = (million == "") ? "" : million + " Million ";
    return "" + million + sixDigits(nonmillion);
}

string nineDigits(int num)
{
    string millions = threeDigits(int(num / 1000000));
    millions = (millions == "Zero") ? "" : millions + " Million ";

    string nonmillions = sixDigits(num % 1000000);

    return "" +
           millions + nonmillions;
}
string tenDigits(int num)
{
    string billions = twoDigits(int(num / 1000000000));
    billions = (billions == "Zero") ? "" : billions + " Billion ";

    string nonbillions = nineDigits(num % 1000000000);

    return "" +
           billions + nonbillions;
}

string
numberToWords(int num)
{
    cout << num << endl;
    string result = "";

    if (num < 10 and num >= 0)
    {
        // cout << "*" << oneDigit(num);
        result = oneDigit(num);
    }

    if (num < 100 and num >= 10)
    {
        // cout << "*" << twoDigits(num);
        result = twoDigits(num);
    }

    if (num < 1000 and num >= 100)
    {
        // cout << threeDigits(num);
        result = threeDigits(num);

        // cout << "*" << twoDigits(num);
    }
    if (num < 10000 and num >= 1000)
    {
        // cout << fourDigits(num);
        result = fourDigits(num);

        // cout << "*" << twoDigits(num);
    }

    if (num < 100000 and num >= 10000)
    {
        // cout << fiveDigits(num);
        result = fiveDigits(num);

        // cout << "*" << twoDigits(num);
    }

    if (num < 1000000 and num >= 100000)
    {
        // cout << sixDigits(num);
        result = sixDigits(num);

        // cout << "*" << twoDigits(num);
    }

    if (num < 10000000 and num >= 1000000)
    {
        // cout << sevenDigits(num);
        result = sevenDigits(num);

        // cout << "*" << twoDigits(num);
    }

    if (num < 100000000 and num >= 10000000)
    {
        // cout << eightDigits(num);
        result = eightDigits(num);

        // cout << "*" << twoDigits(num);
    }
    if (num < 1000000000 and num >= 100000000)
    {
        // cout << eightDigits(num);
        result = nineDigits(num);

        // cout << "*" << twoDigits(num);
    }
    if (num < 10000000000 and num >= 1000000000)
    {
        // cout << eightDigits(num);
        result = tenDigits(num);

        // cout << "*" << twoDigits(num);
    }

    return result;
}

int main()
{
    string word = numberToWords(100);
    cout << word << "|" << endl; // Print the converted word in main
    return 0;
}
