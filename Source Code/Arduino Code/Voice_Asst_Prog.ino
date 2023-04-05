#define CUSTOM_SETTINGS
#define INCLUDE_INTERNET_SHIELD
#define INCLUDE_TERMINAL_SHIELD
#define INCLUDE_TEXT_TO_SPEECH_SHIELD
#define INCLUDE_VOICE_RECOGNIZER_SHIELD
#define INCLUDE_EMAIL_SHIELD
#define INCLUDE_FACEBOOK_SHIELD
#define INCLUDE_PHONE_SHIELD
#define INCLUDE_SMS_SHIELD

#define HALL 22
#define KITCHEN 25
#define BED 26

#define BRIGHT HIGH
#define DARK LOW

char buffer[50];
int flag = 0;

char ch = 'A';
String KtempString = "";
float CtempFloat;
char CtempString[25];

String EmailResponse;
String EmailID = "raiaakashkumar@gmail.com";
String EmailBody = "Detailed Command List: Command-1, Command-2, ... etc.";

String StatusFB, ResponseFB1, ResponseFB2;

String CallPerson;
#define PAPA "1111111111"
#define MUMMY "2222222222"
#define BOSS "4444444444"

String SmsPerson, SmsBody;

const char Intro[] = "please introduce yourself";
const char Greet[] = "hey siri";
const char Health[] = "how are you";
const char Thank[] = "thank you";
const char Features[] = "tell me about your features";
const char Weather[] = "get me the weather updates";
const char Joke[] = "make me laugh";
const char EmailCommand[] = "tell me the available commands";
const char FB[] = "i want to update my status on facebook";
const char Call[] = "i want to make a call";
const char Sms[] = "i want to send a message";
const char HallOn[] = "it's too dark in the hall";
const char HallOff[] = "please turn off the lights of hall";
const char KitchenOn[] = "it's too dark in the kitchen";
const char KitchenOff[] = "please turn off the lights of kitchen";
const char BedOn[] = "it's too dark in the bedroom";
const char BedOff[] = "please turn off the lights of bedroom";
const char AllOff[] = "please turn off all the lights";

#include <OneSheeld.h>
#include "floatToString.h"

HttpRequest request("http://api.openweathermap.org/data/2.5/weather?q=Nadiad&APPID=c4343772cedf2eb91100e5e9a60c6c95");

void setup()
{
  OneSheeld.begin();
  request.setOnSuccess(&onSuccess);
  request.getResponse().setOnJsonResponse(&onJsonReply);
  request.getResponse().setOnError(&onResponseError);
  Internet.setOnError(&onInternetError);

  pinMode(HALL, OUTPUT);
  pinMode(KITCHEN, OUTPUT);
  pinMode(BED, OUTPUT);

}

void loop()
{
  if (VoiceRecognition.isNewCommandReceived())
  {
    if (!strcmp(Weather, VoiceRecognition.getLastCommand()))
    {
      TextToSpeech.say("Sure sir, Just give me a moment.");
      OneSheeld.delay(3000);
      Internet.performGet(request);
    }
    else if (!strcmp(Greet, VoiceRecognition.getLastCommand()))
    {
      TextToSpeech.say("Hey Sir, Make yourself feel comfortable.");
      OneSheeld.delay(3100);
    }
    else if (!strcmp(Intro, VoiceRecognition.getLastCommand()))
    {
      TextToSpeech.say("Hello, I am Siri. I am the smart voice assistant of this DDU Smart Home. I am here to take care of your comfort");
      OneSheeld.delay(9200);
      TextToSpeech.say("I am working on the algorithm made by, Some Instrumentation & Control Engineers.");
      OneSheeld.delay(6000);
    }
    else if (!strcmp(Thank, VoiceRecognition.getLastCommand()))
    {
      TextToSpeech.say("Happy to help you sir.");
      OneSheeld.delay(1300);
    }
    else if (!strcmp(Health, VoiceRecognition.getLastCommand()))
    {
      TextToSpeech.say("Like a charm sir.");
      OneSheeld.delay(1300);
    }
    else if (!strcmp(Features, VoiceRecognition.getLastCommand()))
    {
      TextToSpeech.say("Sir, Various features are included in me by my creators.");
      OneSheeld.delay(3900);
      TextToSpeech.say("For example; Number 1, I can introduce myself, thats make me different from others.");
      OneSheeld.delay(6200);
      TextToSpeech.say("Number 2, I can help you to control your home using voice commands.");
      OneSheeld.delay(4800);
      TextToSpeech.say("Number 3, You can ask me to get weather updates of your city.");
      OneSheeld.delay(4300);
      TextToSpeech.say("Number 4, Suppose you dont know the command list, I can make you aware about that, even i can email it to your email id for your convinience.");
      OneSheeld.delay(9600);
      TextToSpeech.say("Number 5, I can make you laugh sir.");
      OneSheeld.delay(2500);
      TextToSpeech.say("I can help you with your messages, calls and facebook stuffs. And many more...");
      OneSheeld.delay(5300);
    }
    else if (!strcmp(Joke, VoiceRecognition.getLastCommand()))
    {
      switch (random(1, 10))
      {
        case 1 :
          TextToSpeech.say("What do you get from a pampered cow? Spoiled milk");
          OneSheeld.delay(3500);
          break;
        case 2 :
          TextToSpeech.say("What do you get if you divide the circumference of a pumpkin by its diameter? Pumpkin Pi.");
          OneSheeld.delay(5700);
          break;
        case 3 :
          TextToSpeech.say("I'm reading a book about anti-gravity. It's impossible to put down.");
          OneSheeld.delay(4200);
          break;
        case 4 :
          TextToSpeech.say("I'm funny unintentionally, I find it much harder on demand.");
          OneSheeld.delay(3700);
          break;
        case 5 :
          TextToSpeech.say("I can’t believe, I forgot to go to the gym today. That’s 7 years in a row now.");
          OneSheeld.delay(5600);
          break;
        case 6 :
          TextToSpeech.say("A childs observation: If a mother laughs at dad’s jokes, we have guests.");
          OneSheeld.delay(5100);
          break;
        case 7 :
          TextToSpeech.say("If you start to think i talk too much, just tell me. We’ll talk about it.");
          OneSheeld.delay(5200);
          break;
        case 8 :
          TextToSpeech.say("Knock Knock, Who's there? Opportunity! That is impossible. Opportunity doesn’t come knocking twice!");
          OneSheeld.delay(7500);
          break;
        default :
          TextToSpeech.say("How do you make holy water? You boil the hell out of it.");
          OneSheeld.delay(3700);
          break;
      }
    }
    else if (!strcmp(EmailCommand, VoiceRecognition.getLastCommand()))
    {
      TextToSpeech.say("Sure sir, List of basic commands is as follow :");
      OneSheeld.delay(3600);
      TextToSpeech.say("Number 1, To turn ON or turn OFF the lights of hall, say 'hallon' or 'halloff'.");
      OneSheeld.delay(6200);
      TextToSpeech.say("Number 2, Command remains the same for kitchen and bedroom. Just replace the word 'hall' with the appropriate word.");
      OneSheeld.delay(8100);
      TextToSpeech.say("Sir, Command list is too long. I will send the detailed list to your email id.");
      OneSheeld.delay(5600);
      TextToSpeech.say(EmailID);
      OneSheeld.delay(3200);

      Email.send(EmailID, "Siri's Command List", EmailBody);

      TextToSpeech.say("Email sent sir. Check your inbox.");
      OneSheeld.delay(2700);
    }
    else if (!strcmp(FB, VoiceRecognition.getLastCommand()))
    {
      TextToSpeech.say("Why not Sir, Just tell me your status. I will update it for you.");
      OneSheeld.delay(4650);

RepeatFB2:

      VoiceRecognition.start();
      while (!VoiceRecognition.isNewCommandReceived())
      {
        if (flag == 0)
        {
          Terminal.println("FB : Tell me your status.");
          flag = 1;
        }
        else
        {
          OneSheeld.delay(10);
        }
      }
      flag = 0;

      StatusFB = VoiceRecognition.getLastCommand();
      TextToSpeech.say("Your status is : ");
      OneSheeld.delay(1400);
      TextToSpeech.say(StatusFB);
      OneSheeld.delay(5000);
      TextToSpeech.say("Should i proceed further and update your status?");
      OneSheeld.delay(2800);

RepeatFB1:

      VoiceRecognition.start();
      while (!VoiceRecognition.isNewCommandReceived())
      {
        if (flag == 0)
        {
          Terminal.println("FB : Should i proceed further and update your status?");
          flag = 1;
        }
        else
        {
          OneSheeld.delay(10);
        }
      }
      flag = 0;
      ResponseFB1 = VoiceRecognition.getLastCommand();
      ResponseFB1.toCharArray(buffer, 50);
      if (!strcmp("yes", buffer))
      {
        Facebook.post(StatusFB);
        TextToSpeech.say("Status updated sir. Soon you will start receiving likes and comments.");
        OneSheeld.delay(4800);
      }
      else if (!strcmp("no", buffer))
      {
        TextToSpeech.say("No worries sir, status discarded. Want to do changes in your status or you want to cancel your facebook status update?");
        OneSheeld.delay(7850);

RepeatFB3:

        VoiceRecognition.start();
        while (!VoiceRecognition.isNewCommandReceived())
        {
          if (flag == 0)
          {
            Terminal.println("FB : Want to do changes in your status or you want to cancel your facebook status update?");
            flag = 1;
          }
          else
          {
            OneSheeld.delay(10);
          }
        }
        flag = 0;
        ResponseFB2 = VoiceRecognition.getLastCommand();
        ResponseFB2.toCharArray(buffer, 50);
        if (!strcmp("just cancel it", buffer ))
        {
          TextToSpeech.say("Okay Sir. Forget it.");
          OneSheeld.delay(2100);
        }
        else if (!strcmp("i want to do changes in my status", buffer))
        {
          TextToSpeech.say("Fine sir. Tell Me your status");
          OneSheeld.delay(2700);
          goto RepeatFB2;
        }
        else
        {
          TextToSpeech.say("If you want to edit your status, say 'i want to do changes in my status' and if you want to cancel the facebook status update, say 'just cancel it'");
          OneSheeld.delay(10200);
          goto RepeatFB3;
        }
      }
      else
      {
        TextToSpeech.say("If you want to upload your status on facebook, say 'yes' and if you want to edit your status, say 'no'.");
        OneSheeld.delay(8200);
        goto RepeatFB1;
      }
    }
    else if (!strcmp(Call, VoiceRecognition.getLastCommand()))
    {
      TextToSpeech.say("No problem sir, Just tell me the name of the person.");
      OneSheeld.delay(3300);

      VoiceRecognition.start();
      while (!VoiceRecognition.isNewCommandReceived())
      {
        if (flag == 0)
        {
          Terminal.println("Call : Tell me the name of the person, to whom you want to call.");
          flag = 1;
        }
        else
        {
          OneSheeld.delay(10);
        }
      }
      flag = 0;
      CallPerson = VoiceRecognition.getLastCommand();
      CallPerson.toCharArray(buffer, 50);
      if (!strcmp("papa", buffer))
      {
        TextToSpeech.say("Connecting you with your daddy.");
        OneSheeld.delay(2000);
        Phone.call(PAPA);
      }
      else if (!strcmp("mummy", buffer))
      {
        TextToSpeech.say("Connecting you with your mom.");
        OneSheeld.delay(2000);
        Phone.call(MUMMY);
      }
      else if (!strcmp("boss", buffer))
      {
        TextToSpeech.say("Calling your");
        OneSheeld.delay(1100);
        TextToSpeech.say(CallPerson);
        OneSheeld.delay(500);
        Phone.call(BOSS);
      }
      else
      {
        TextToSpeech.say("This person is not defined in my contacts library.");
        OneSheeld.delay(3500);
      }
    }
    else if (!strcmp(Sms, VoiceRecognition.getLastCommand()))
    {
      TextToSpeech.say("No problem sir, Just tell me the name of the person.");
      OneSheeld.delay(3300);

      VoiceRecognition.start();
      while (!VoiceRecognition.isNewCommandReceived())
      {
        if (flag == 0)
        {
          Terminal.println("SMS : Tell me the name of the person, to whom you want to send the message.");
          flag = 1;
        }
        else
        {
          OneSheeld.delay(10);
        }
      }
      flag = 0;
      SmsPerson = VoiceRecognition.getLastCommand();
      SmsPerson.toCharArray(buffer, 50);
      if (!strcmp("papa", buffer))
      {
        TextToSpeech.say("Tell me the message you want to send.");
        OneSheeld.delay(2300);
        VoiceRecognition.start();
        while (!VoiceRecognition.isNewCommandReceived())
        {
          if (flag == 0)
          {
            Terminal.println("SMS : Tell me the message you want me to send to your daddy");
            flag = 1;
          }
          else
          {
            OneSheeld.delay(10);
          }
        }
        flag = 0;
        SmsBody = VoiceRecognition.getLastCommand();
        TextToSpeech.say("Sending the message to your daddy.");
        OneSheeld.delay(2200);
        SMS.send(PAPA, SmsBody);
        TextToSpeech.say("Message sent.");
        OneSheeld.delay(1200);
      }
      else if (!strcmp("mummy", buffer))
      {
        TextToSpeech.say("Tell me the message you want to send.");
        OneSheeld.delay(2300);
        VoiceRecognition.start();
        while (!VoiceRecognition.isNewCommandReceived())
        {
          if (flag == 0)
          {
            Terminal.println("SMS : Tell me the message you want me to send to your mom");
            flag = 1;
          }
          else
          {
            OneSheeld.delay(10);
          }
        }
        flag = 0;
        SmsBody = VoiceRecognition.getLastCommand();
        TextToSpeech.say("Sending the message to your mom");
        OneSheeld.delay(2200);
        SMS.send(MUMMY, SmsBody);
        TextToSpeech.say("Message sent.");
        OneSheeld.delay(1200);
      }
      else if (!strcmp("boss", buffer))
      {
        TextToSpeech.say("Tell me the message you want to send.");
        OneSheeld.delay(2300);
        VoiceRecognition.start();
        while (!VoiceRecognition.isNewCommandReceived())
        {
          if (flag == 0)
          {
            Terminal.println("SMS : Tell me the message you want me to send to your boss");
            flag = 1;
          }
          else
          {
            OneSheeld.delay(10);
          }
        }
        flag = 0;
        SmsBody = VoiceRecognition.getLastCommand();
        TextToSpeech.say("Sending the message to your");
        OneSheeld.delay(1600);
        TextToSpeech.say(SmsPerson);
        OneSheeld.delay(500);
        SMS.send(BOSS, SmsBody);
        TextToSpeech.say("Message sent.");
        OneSheeld.delay(1200);
      }
      else
      {
        TextToSpeech.say("This person is not defined in my contacts library");
        OneSheeld.delay(3500);
      }
    }
    else if (!strcmp(HallOn, VoiceRecognition.getLastCommand()))
    {
      TextToSpeech.say("Okay sir, Turning ON the lights in the hall.");
      OneSheeld.delay(2700);
      digitalWrite(HALL, BRIGHT);
      TextToSpeech.say("It's done. You should be feeling comfortable now");
      OneSheeld.delay(3200);
    }
    else if (!strcmp(HallOff, VoiceRecognition.getLastCommand()))
    {
      TextToSpeech.say("As you wish sir, Turning OFF the lights in the hall.");
      OneSheeld.delay(3000);
      digitalWrite(HALL, DARK);
      TextToSpeech.say("It's done. Don't worry sir, I am not afraid of dark.");
      OneSheeld.delay(4100);
    }
    else if (!strcmp(KitchenOn, VoiceRecognition.getLastCommand()))
    {
      TextToSpeech.say("As you wish sir, Turning ON the lights in the kitchen. Enjoy your time");
      OneSheeld.delay(4800);
      digitalWrite(KITCHEN, BRIGHT);
      TextToSpeech.say("Task done, A quote for you sir : The kitchens are made for bringing family together.");
      OneSheeld.delay(5600);
    }
    else if (!strcmp(KitchenOff, VoiceRecognition.getLastCommand()))
    {
      TextToSpeech.say("As you wish sir, Turning OFF the lights in the kitchen.");
      OneSheeld.delay(2900);
      digitalWrite(KITCHEN, DARK);
      TextToSpeech.say("Task completed sir. A quote for you : What hurts you, blesses you. Darkness is your candle.");
      OneSheeld.delay(7200);
    }
    else if (!strcmp(BedOn, VoiceRecognition.getLastCommand()))
    {
      TextToSpeech.say("Okay sir, Turning ON the lights in the bedroom.");
      OneSheeld.delay(2900);
      digitalWrite(BED, BRIGHT);
      TextToSpeech.say("It's done sir. ");
      OneSheeld.delay(1200);
    }
    else if (!strcmp(BedOff, VoiceRecognition.getLastCommand()))
    {
      TextToSpeech.say("As you wish sir, Turning OFF the lights in the bedroom.");
      OneSheeld.delay(3100);
      digitalWrite(BED, DARK);
      TextToSpeech.say("Task completed. Don't get afraid sir. I'm here.");
      OneSheeld.delay(4200);
    }
    else if (!strcmp(AllOff, VoiceRecognition.getLastCommand()))
    {
      TextToSpeech.say("As you wish sir, Turning OFF all the lights.");
      OneSheeld.delay(2800);
      digitalWrite(HALL, DARK);
      digitalWrite(KITCHEN, DARK);
      digitalWrite(BED, DARK);
      TextToSpeech.say("Sir, You know what? Now i can hear your heart beating.");
      OneSheeld.delay(4800);
    }
    else
    {
      TextToSpeech.say("I beg your pardon sir, I don't know how to respond to that command.");
      OneSheeld.delay(4800);
    }
  }
}

void onSuccess(HttpResponse & response)
{
  response["name"].query();
  OneSheeld.delay(1000);
  response["main"]["temp"].query();
  OneSheeld.delay(1000);
  response["main"]["humidity"].query();
  OneSheeld.delay(1000);
  response["weather"][0]["description"].query();
  OneSheeld.delay(1000);
}

void onJsonReply(JsonKeyChain & hell, char * output)
{
  switch (ch)
  {
    case 'A' :  ch = 'B';
      TextToSpeech.say("City");
      Terminal.print("City : ");
      OneSheeld.delay(800);
      TextToSpeech.say(output);
      Terminal.println(output);
      OneSheeld.delay(1000);
      break;

    case 'B' :  ch = 'C';
      KtempString = output;
      CtempFloat = KtempString.toFloat() - 273;
      floatToString(CtempString, CtempFloat, 3);

      TextToSpeech.say("Temprature");
      Terminal.print("Temprature : ");
      OneSheeld.delay(1000);
      TextToSpeech.say(CtempString);
      Terminal.print(CtempString);
      OneSheeld.delay(1500);
      TextToSpeech.say("Degree Centigrade");
      Terminal.println(" Degree Centigrade");
      OneSheeld.delay(1000);
      break;

    case 'C' :  ch = 'D';
      TextToSpeech.say("Humidity");
      Terminal.print("Humidity : ");
      OneSheeld.delay(1000);
      TextToSpeech.say(output);
      Terminal.print(output);
      OneSheeld.delay(500);
      TextToSpeech.say("Percent");
      Terminal.println(" %");
      OneSheeld.delay(1000);
      break;

    case 'D' :  ch = 'A';
      TextToSpeech.say("Weather");
      Terminal.print("Weather : ");
      OneSheeld.delay(1000);
      TextToSpeech.say(output);
      Terminal.println(output);
      OneSheeld.delay(1500);
      break;

    default :   ch = 'A';
      TextToSpeech.say("Error Occured");
      Terminal.println(output);
      OneSheeld.delay(5000);
  }
}

void onResponseError(int errorNumber)
{
  Terminal.print("Response error:");
  switch (errorNumber)
  {
    case INDEX_OUT_OF_BOUNDS: Terminal.println("INDEX_OUT_OF_BOUNDS"); break;
    case RESPONSE_CAN_NOT_BE_FOUND: Terminal.println("RESPONSE_CAN_NOT_BE_FOUND"); break;
    case HEADER_CAN_NOT_BE_FOUND: Terminal.println("HEADER_CAN_NOT_BE_FOUND"); break;
    case NO_ENOUGH_BYTES: Terminal.println("NO_ENOUGH_BYTES"); break;
    case REQUEST_HAS_NO_RESPONSE: Terminal.println("REQUEST_HAS_NO_RESPONSE"); break;
    case SIZE_OF_REQUEST_CAN_NOT_BE_ZERO: Terminal.println("SIZE_OF_REQUEST_CAN_NOT_BE_ZERO"); break;
    case UNSUPPORTED_HTTP_ENTITY: Terminal.println("UNSUPPORTED_HTTP_ENTITY"); break;
    case JSON_KEYCHAIN_IS_WRONG: Terminal.println("JSON_KEYCHAIN_IS_WRONG"); break;
  }
}

void onInternetError(int requestId, int errorNumber)
{
  Terminal.print("Request id:");
  Terminal.println(requestId);
  Terminal.print("Internet error:");
  switch (errorNumber)
  {
    case REQUEST_CAN_NOT_BE_FOUND: Terminal.println("REQUEST_CAN_NOT_BE_FOUND"); break;
    case NOT_CONNECTED_TO_NETWORK: Terminal.println("NOT_CONNECTED_TO_NETWORK"); break;
    case URL_IS_NOT_FOUND: Terminal.println("URL_IS_NOT_FOUND"); break;
    case ALREADY_EXECUTING_REQUEST: Terminal.println("ALREADY_EXECUTING_REQUEST"); break;
    case URL_IS_WRONG: Terminal.println("URL_IS_WRONG"); break;
  }
}

