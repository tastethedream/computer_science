import qrcode

image = qrcode.make("type input here")
image.save("qr.png", "PNG")