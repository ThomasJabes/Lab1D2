//****************************************************************************************
//Universidad del Valle de Guatemala 
//IE3054 : Digital 2
// Author : ALan
// Laboratorio : 1
// ATMEGA328P 
// Created: 12/07/2024 12:17:32
//*********************************************************************************************

#define F_CPU 16000000UL // Frecuencia del microcontrolador
#include <avr/io.h>
#include <util/delay.h>

// Configuraci�n del pin para el bot�n
#define BUTTON_PIN PINC
#define BUTTON_PORT PORTC
#define BUTTON_DDR DDRC
#define BUTTON PC4

// Configuraci�n del pin para el LED
#define LED_PORT PORTC
#define LED_DDR DDRC
#define LED PC3

void setup() {
	// Configuraci�n del pin del LED como salida
	LED_DDR |= (1 << LED);
	LED_PORT &= ~(1 << LED); // Apaga el LED inicialmente
	
	// Configuraci�n del pin del bot�n como entrada con pull-up
	BUTTON_DDR &= ~(1 << BUTTON);
	BUTTON_PORT |= (1 << BUTTON);
}

int main(void) {
	setup();

	while (1) {
		// Comprueba si el bot�n est� presionado
		if (!(BUTTON_PIN & (1 << BUTTON))) {
			// Enciende el LED
			LED_PORT |= (1 << LED);
			} else {
			// Apaga el LED
			LED_PORT &= ~(1 << LED);
		}
	}

	return 0;
}
