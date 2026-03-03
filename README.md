🚮 Smart Moving Dustbin (Ultrasonic Based) 🤖

An Arduino-based smart dustbin that moves toward you and opens automatically when you come close.

No camera.
No AI.
Just smart use of ultrasonic sensing and motor control.

📌 Project Overview

This project uses an ultrasonic sensor to detect a person.

When a person is within range:

🛞 The dustbin moves forward

🛑 Stops when very close

🔓 Opens the lid using a servo motor

⏳ Waits for 5 seconds

🔒 Closes automatically

🧠 Working Logic
| Distance Range | Action          |
| -------------- | --------------- |
| > 60 cm        | Stop            |
| 30–60 cm       | Move Forward    |
| < 15 cm        | Stop + Open Lid |

📺 Project Demo

Click the thumbnail below to watch the working project:
[![Watch the Demo](https://img.youtube.com/vi/znmPFGG9ZqM/0.jpg)](https://youtu.be/znmPFGG9ZqM)
