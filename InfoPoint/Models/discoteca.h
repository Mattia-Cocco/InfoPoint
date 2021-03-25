#ifndef DISCOTECA_H
#define DISCOTECA_H
#include"locale.h"

class Discoteca: public virtual Locale
{
private:
    bool ingresso;
    unsigned int prezzo_ingresso;
public:
    Discoteca(string="", string ="",string="",string="",string="",string="",string="",bool=false, unsigned int=0);
    Discoteca(const Discoteca&);

    virtual string getInfo() const override ;
    virtual ~Discoteca() override = default;
    virtual string getTipo() const override;
    bool getIngresso()const;
    unsigned int getP_ing()const;
};

#endif // DISCOTECA_H
