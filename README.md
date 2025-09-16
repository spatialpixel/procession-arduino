# ProcesionArduino

Simple Arduino library for interacting with Spatial Pixel's "Procession" app.

## What is Procession?

Procession is a spatial computing web app that enables designers and creatives
to prototype interactive experiences with natural language programming techniques.

+ More info here on Spatial Pixel's [Procession page](https://spatialpixel.com/procession/)
+ [Hosted online here.](https://procession.spatialpixel.com/)
+ Built by [Spatial Pixel](https://spatialpixel.com/)

## ProcessionArduino.h

Used for connecting an Arduino-based microcontroller to Procession via a USB
port. Provides simple `send()` and `receive()` methods for sending values to
and receiving values from a particular topic on the pubsub system in a Procession
sketch.
