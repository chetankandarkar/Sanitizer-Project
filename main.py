import conf
from boltiot import Sms, Bolt
import json, time


mybolt = Bolt(conf.API_KEY, conf.DEVICE_ID)
sms = Sms(conf.SID, conf.AUTH_TOKEN, conf.TO_NUMBER, conf.FROM_NUMBER)

while True:
print ("Reading sensor value")
response = mybolt.digitalRead('0')
data = json.loads(response)
print("Value getting from Arduino : " + str(data['value']))
try:
sensor_value = int(data['value'])
if sensor_value == 0:
print("Making request to Twilio to send a SMS")
response = sms.send_sms("Alert ! Somebody would not use sanitizer")
print("Response received from Twilio is: " + str(response))
print("Status of SMS at Twilio is :" + str(response.status))
break

except Exception as e:
print ("Error occured: Below are the details")
print (e)
