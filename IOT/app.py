from flask import Flask, render_template
import serial
import time

try:
    arduino = serial.Serial(port='COM3', baudrate=9600, timeout=.1)
    time.sleep(2)  # wait for the serial connection to initialize
except serial.SerialException as e:
    print(f"Error connecting to Arduino: {e}")
    arduino = None

app = Flask(__name__)

# Rota principal que renderiza a página HTML
@app.route('/')
def index():
    return render_template('index.html')

# Rota que recebe os comandos do HTML e os envia para o Arduino
@app.route('/control/<device>/<action>')
def control(device, action):
    if arduino:
        command = ''
        if device == '1':  # LED Verde
            command = 'A' if action == 'on' else 'a'
        elif device == '2':  # LED Vermelho
            command = 'B' if action == 'on' else 'b'
        elif device == '3':  # Buzzer
            command = 'C' if action == 'on' else 'c'

        if command:
            arduino.write(command.encode())
            return f"Comando '{command}' enviado para o dispositivo {device}."
        else:
            return "Comando inválido."
    else:
        return "Arduino não conectado."

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000, use_reloader=False)