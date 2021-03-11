let serial; // variable for the serial object
let bright = 0; // variable to hold the data we're sending

function setup() {
  createCanvas(512, 512);

  // serial constructor
  serial = new p5.SerialPort();

  // serial port to use - you'll need to change this
  serial.open('/dev/cu.usbmodem14101');
}


function draw() {
  background(220);
  if (bright == 1) {
    background(220);
  } else {
    background(0);
  }
}

  function mousePressed() {
    if (bright == 1) {
      bright = 0;
       serial.write(bright);
    console.log(bright);
    } else {
      bright = 1;
       serial.write(bright);
    console.log(bright);
    }
  }