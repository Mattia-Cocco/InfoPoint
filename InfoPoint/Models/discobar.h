#ifndef DISCOBAR_H
#define DISCOBAR_H


#include "bar.h"
#include "discoteca.h"

class Discobar: public Bar, public Discoteca{
private:
    string costo_drink;
public:
    Discobar(string="", string="",string="",string="",string="",string="",string="",bool=false, bool=false, unsigned int=0, string="");
    Discobar(const Discobar&);

    virtual string getTipo() const override;
    virtual string getInfo() const override;
    virtual ~Discobar() override = default;
    string getCosto_drink()const;
};
#endif // DISCOBAR_H
