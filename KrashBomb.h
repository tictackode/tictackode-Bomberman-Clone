


class KrashBomb
{
   public:
   int x_location;
   int y_location;
   int rangeOfExplosion;
   volatile int activationTime;
   bool bombIsSet;
   BITMAP* imagem;

   KrashBomb()
   {
        this->rangeOfExplosion=1;
        this->bombIsSet=false;
   }
   KrashBomb(volatile int timer,int x_location,int y_location,int rangeOfExplosion)
   {
       this->x_location=x_location;
       this->y_location=y_location;
       this->rangeOfExplosion=rangeOfExplosion;
       this->activationTime=timer;
   }

   ~KrashBomb()
   {
        delete &x_location;
        delete &y_location;
        delete &rangeOfExplosion;
        delete &activationTime;
        delete &bombIsSet;
        delete &imagem;
        delete this;
   }

    void setKrashBomb(volatile int timer,int x_location,int y_location,int rangeOfExplosion)
   {
       this->x_location=x_location;
       this->y_location=y_location;
       this->rangeOfExplosion=rangeOfExplosion;
       this->activationTime=timer;
       this->bombIsSet=true;
   }
   void checkExplosion();

};
