import conf
from boltiot import Email, Sms, Bolt
import json, time


mybolt = Bolt(conf.API_KEY, conf.DEVICE_ID)
sms = Sms(conf.SID, conf.AUTH_TOKEN, conf.TO_NUMBER, conf.FROM_NUMBER)
mailer = Email(conf.MAILGUN_API_KEY, conf.SANDBOX_URL, conf.SENDER_EMAIL, conf.RECIPIENT_EMAIL)

while True:
print ("Reading sensor value")
response = mybolt.digitalRead('0')
data = json.loads(response)
print("Value getting from Arduino : " + str(data['value']))
try:
sensor_value = int(data['value'])
if sensor_value == 0:
print("Making request to Twilio to send a SMS")
print("Making request to Mailgun to send an email")
response = mailer.send_email("Alert", "Somebody would not use sanitizer")
response_text = json.loads(response.text)
print("Response received from Mailgun is: " + str(response_text['message']))
response = sms.send_sms("Alert ! Somebody would not use sanitizer")
print("Response received from Twilio is: " + str(response))
print("Status of SMS at Twilio is :" + str(response.status))
break

except Exception as e:
print ("Error occured: Below are the details")
print (e)
