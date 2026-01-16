#ifndef Device_H_
#define Device_H_

#include <Arduino.h>

class Device{
  protected:
    String nom;
    uint8_t pin;
    static int nb_devices;
  public:
    /**
     *@fn Device(String name, uint8_t pin)
     *@brief Constructeur de la classe Device
     *@param name nom à donner au périphérique
     *@param pin broche du gpio de l'arduino
    */
    Device(String name, uint8_t pin);

    /**
     *@fn ~Device
     *@brief Destructeur, décrémente le compteur nb_devices
    */
    ~Device();

    /**
     *@fn String getnom()
     *@brief retourne le nom du device
     *@return String le nom du device
    */
    String getnom();

    /**
     *@fn uint8_t getpin()
     *@brief retourne le pin associé au device
     *@return uint8_t le numéro de la broche 
    */
    uint8_t getpin();

    /**
     *@fn int getnbdevices()
     *@brief retourne le nombre total de périphériques créés
     *@return int valeur du compteur
    */
    static int getnbdevices();

    /**
     *@fn virtual void initialisation()= 0
     *@brief initialise le périphérique
     *@details Doit être définie par les classes filles
    */
    virtual void initialisation()= 0;
};

#endif