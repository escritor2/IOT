#include <Arduino.h>

int led = 13;
String mensagem = "SOS";

// Durações em milissegundos
int ponto = 200;
int traco = 600;
int pausaEntre = 200;
int pausaLetra = 600;
int pausaPalavra = 1400;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  transmitirMorse(mensagem);
  delay(5000); // Espera 5 segundos antes de repetir
}

void transmitirMorse(String texto) {
  for(int i = 0; i < texto.length(); i++) {
    char letra = texto.charAt(i);
    
    if(letra == ' ') {
      delay(pausaPalavra);
    } else {
      String codigo = letraParaMorse(letra);
      transmitirCodigo(codigo);
      delay(pausaLetra);
    }
  }
}

String letraParaMorse(char letra) {
  letra = toupper(letra);
  switch(letra) {
    case 'A': return ".-";
    case 'B': return "-...";
    case 'C': return "-.-.";
    case 'D': return "-..";
    case 'E': return ".";
    case 'F': return "..-.";
    case 'G': return "--.";
    case 'H': return "....";
    case 'I': return "..";
    case 'J': return ".---";
    case 'K': return "-.-";
    case 'L': return ".-..";
    case 'M': return "--";
    case 'N': return "-.";
    case 'O': return "---";
    case 'P': return ".--.";
    case 'Q': return "--.-";
    case 'R': return ".-.";
    case 'S': return "...";
    case 'T': return "-";
    case 'U': return "..-";
    case 'V': return "...-";
    case 'W': return ".--";
    case 'X': return "-..-";
    case 'Y': return "-.--";
    case 'Z': return "--..";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
    case '0': return "-----";
    default: return "";
  }
}

void transmitirCodigo(String codigo) {
  for(int i = 0; i < codigo.length(); i++) {
    char simbolo = codigo.charAt(i);
    
    digitalWrite(led, HIGH);
    if(simbolo == '.') {
      delay(ponto);
    } else if(simbolo == '-') {
      delay(traco);
    }
    digitalWrite(led, LOW);
    
    delay(pausaEntre);
  }
}