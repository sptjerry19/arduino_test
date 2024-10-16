#include <FS.h>
bool saveData(const char* filename, const char* content, uint16_t len)
{
  SPIFFS.begin();
  File file = SPIFFS.open(String("/")+filename, "a");
  if (!file) {
    file.close();
    return false;
  } else {
    file.write((const uint8_t*)content, len);
    file.close(); 
    return true;
  }
}

String readData(const char* filename)
{
  SPIFFS.begin();
  File file = SPIFFS.open(String("/")+filename, "r");
  String temp = file.readString();
  file.close();
  return temp;
}