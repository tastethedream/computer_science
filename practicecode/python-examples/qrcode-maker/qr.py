import qrcode 

# todo - user input their qr request
# todo - qrcode.make(dynamically add user input here)
# todo - dynamically create file names when saving png

your_message = input("Create your QR code: ")

image = qrcode.make(your_message)
image.save("testing.png", "PNG")
print("Your QR code was generated. Check your file library")
