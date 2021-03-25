#ifndef BAR_H
#define BAR_H
#include "locale.h"


class Bar: public virtual Locale{
private:
    bool postiASedere;
public:
    Bar(string="", string="",string="",string="",string="",string="",string="", bool=false);
    Bar(const Bar&);


    virtual string getInfo() const override ;
    virtual string getTipo() const override ;
    bool getPostiASedere()const;
    virtual ~Bar() override = default;
};


std::ostream& operator<<(std::ostream&, const Bar&);


#endif // BAR_H

