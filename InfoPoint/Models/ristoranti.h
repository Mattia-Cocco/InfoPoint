#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "locale.h"

class Ristorante: public Locale{
   bool coperto;
public:
   Ristorante(string="", string="",string="",string="",string="",string="",string="", bool =true);
   Ristorante(const Ristorante&);


    virtual string getTipo()  const override;
    virtual string getInfo() const override ;
    bool getCoperto()const;
    virtual  ~Ristorante()override=default;


};

#endif // RESTAURANT_H
