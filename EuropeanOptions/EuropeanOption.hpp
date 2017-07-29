#ifndef EUROPEANOPTION_HPP
#define EUROPEANOPTION_HPP
using namespace std;
#include <iostream>

class EuropeanOption{
private:
    void init();
    void copy(const EuropeanOption& o2);
    double CallPrice() const;
    double PutPrice() const;
    double CallDelta() const;
    double PutDelta() const;
public:
    // Public member data for convenience only
    double r; // Interest rate
    double sig; // Volatility
    double K; // Strike price
    double T; // Excout << "Put option on future: " << futureOption.Price() << endl;
    double U; // Current underlying price
    double b; // Cost of carry
    string optType; // Option name (call, put)
public:
    // Constructors
    EuropeanOption(); // Default call option
    EuropeanOption(const EuropeanOption& option2); // Copy constructor
    EuropeanOption (const string& optionType); // Create option type
    // Destructor
    virtual ~EuropeanOption();
    // Assignment operator
    EuropeanOption& operator = (const EuropeanOption& option2);
    // Functions that calculate option price and (some) sensitivities
    double Price() const;
    double Delta() const;
    // Modifier functions
    void toggle(); // Change option type (C/P, P/C)
};

#endif






