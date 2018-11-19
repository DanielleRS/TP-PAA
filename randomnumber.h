#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H


class RandomNumber
{
  public:
    RandomNumber();
    RandomNumber(unsigned int);
    unsigned int generate();

  private:
    unsigned int superiorLimit;
};

#endif // RANDOMNUMBER_H
