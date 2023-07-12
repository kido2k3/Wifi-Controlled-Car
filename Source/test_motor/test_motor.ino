
int enco = 2;
int dem = 0;
double rpm = 0;

int timecho = 1000;
unsigned long thoigian;
unsigned long hientai;

void dem_xung()
{
  dem++; //đếm xung
}

void setup() 
{
  Serial.begin(9600);
  
  pinMode(enco, INPUT);
  attachInterrupt(0, dem_xung, RISING);
}

void loop() 
{
  thoigian = millis();
//  Serial.print("Time: "); Serial.print(thoigian); Serial.print("   ");
//  Serial.print("Hiện tại: "); Serial.println(hientai);
  
  if (thoigian - hientai >= timecho)
  {
    hientai = thoigian;
    rpm = (dem*1.0/20)*60; 
        /*
         * Đĩa encoder có 20 xung, chúng ta đo được 120 xung/s
         * vậy lấy 120/20 = 6 vòng/s
         * ta được: 6*60 = số vòng quay / phút (RPM)
         */
    Serial.print("\t\t\t\t"); Serial.print("Số xung/s: "); Serial.println(dem);
    dem = 0;   
    Serial.print("\t\t\t\t"); Serial.print("RPM: "); Serial.println(rpm);
  }
}
