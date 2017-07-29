#include "EuropeanOption.hpp" // declarations of functions
#include <math.h>
// N is the phi function here, the standard normal distribution
double EuropeanOption::PutPrice()const{
    double tmp = sig * sqrt(T);
    double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
    double d2 = d1 - tmp;
    return (K * exp(-r * T)* N(-d2)) - (U * exp((b-r)*T) * N(-d1));
    // calculates the price of a put option using black scholes
    // data is taken from the member data -> EuropeanOption
}

double EuropeanOption::CallPrice()const{
    double tmp = sig * sqrt(T);
    double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
    double d2 = d1 - tmp;
    return (U * exp((b-r)*T) * N(d1)) - (K * exp(-r * T)* N(d2));
    // black scholes for call options

}

double EuropeanOption::CallDelta() const
{
    double tmp = sig * sqrt(T);
    double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
    return exp((b-r)*T) * N(d1);
}

double EuropeanOption::PutDelta() const
{
    double tmp = sig * sqrt(T);
    double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
    return exp((b-r)*T) * (N(d1) - 1.0);
}

void EuropeanOption::init()
{ // Initialise all default cout << "Put option on future: " << futureOption.Price() << endl;
// Now change over to a call on the option
futureOption.toggle();
cout << "Call on future: " << futureOption.Price() << endl;
return 0;
}values
// Default values
    r = 0.08;
    sig = 0.30;
    K = 65.0;
    T = 0.25;
    U = 60.0; // U == stock in this case
    b = r; // Black and Scholes stock option model (1973)
    optType = "C"; // European Call Option (the default type)
}

EuropeanOption::EuropeanOption()
{ // Default call option
    init();
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2)
{ // Copy constructor
    copy(o2);
}

EuropeanOption::EuropeanOption (const string& optionType)
{ // Create option type
    init();
    optType = optionType;
    if (optType == "c")
    optType = "C";
}

EuropeanOption::~EuropeanOption(){ // Destructor
}

EuropeanOption& EuropeanOption::operator = (const EuropeanOption& opt2)
{ // Assignment operator (deep copy)
    if (this == &opt2) return *this;
    copy (opt2);
    return *this;
}

// Functions that calculate option price and sensitivities
double Europea8nOption::Price() const
{
if (optType == "C")
    {
    return CallPrice();
    }
else{return PutPrice();}
}

double EuropeanOption::Delta() const
{
if (optType == "C"){return CallDelta();}
else{return PutDelta();}
}

// Modifier functions
void EuropeanOption::toggle()
{ // Change option type (C/P, P/C)
    if (optType == "C"){optType = "P";}
    else{optType = "C";}
}

