#include <WiFi.h>
#include "esp_wifi.h"

esp_err_t esp_wifi_80211_tx(wifi_interface_t ifx, const void *buffer, int len, bool en_sys_seq);

// Create the default config
wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();

// Set the delay for transmitting packets
uint32_t currentTime = 0;
uint32_t attackTime = 0;
uint32_t attackDelay = 10;

// Set the SSIDs to broadcast
int currentID = 0;
const int numIDs = 250;
const char* ssids[numIDs] = {
  "HackedWiFi_1\n",
  "HackedWiFi_2\n",
  "HackedWiFi_3\n",
  "HackedWiFi_4\n",
  "HackedWiFi_5\n",
  "HackedWiFi_6\n",
  "HackedWiFi_7\n",
  "HackedWiFi_8\n",
  "HackedWiFi_9\n",
  "HackedWiFi_10\n",
  "HackedWiFi_11\n",
  "HackedWiFi_12\n",
  "HackedWiFi_13\n",
  "HackedWiFi_14\n",
  "HackedWiFi_15\n",
  "HackedWiFi_16\n",
  "HackedWiFi_17\n",
  "HackedWiFi_18\n",
  "HackedWiFi_19\n",
  "HackedWiFi_20\n",
  "HackedWiFi_21\n",
  "HackedWiFi_22\n",
  "HackedWiFi_23\n",
  "HackedWiFi_24\n",
  "HackedWiFi_25\n",
  "HackedWiFi_26\n",
  "HackedWiFi_27\n",
  "HackedWiFi_28\n",
  "HackedWiFi_29\n",
  "HackedWiFi_30\n",
  "HackedWiFi_31\n",
  "HackedWiFi_32\n",
  "HackedWiFi_33\n",
  "HackedWiFi_34\n",
  "HackedWiFi_35\n",
  "HackedWiFi_36\n",
  "HackedWiFi_37\n",
  "HackedWiFi_38\n",
  "HackedWiFi_39\n",
  "HackedWiFi_40\n",
  "HackedWiFi_41\n",
  "HackedWiFi_42\n",
  "HackedWiFi_43\n",
  "HackedWiFi_44\n",
  "HackedWiFi_45\n",
  "HackedWiFi_46\n",
  "HackedWiFi_47\n",
  "HackedWiFi_48\n",
  "HackedWiFi_49\n",
  "HackedWiFi_50\n",
  "HackedWiFi_51\n",
  "HackedWiFi_52\n",
  "HackedWiFi_53\n",
  "HackedWiFi_54\n",
  "HackedWiFi_55\n",
  "HackedWiFi_56\n",
  "HackedWiFi_57\n",
  "HackedWiFi_58\n",
  "HackedWiFi_59\n",
  "HackedWiFi_60\n",
  "HackedWiFi_61\n",
  "HackedWiFi_62\n",
  "HackedWiFi_63\n",
  "HackedWiFi_64\n",
  "HackedWiFi_65\n",
  "HackedWiFi_66\n",
  "HackedWiFi_67\n",
  "HackedWiFi_68\n",
  "HackedWiFi_69\n",
  "HackedWiFi_70\n",
  "HackedWiFi_71\n",
  "HackedWiFi_72\n",
  "HackedWiFi_73\n",
  "HackedWiFi_74\n",
  "HackedWiFi_75\n",
  "HackedWiFi_76\n",
  "HackedWiFi_77\n",
  "HackedWiFi_78\n",
  "HackedWiFi_79\n",
  "HackedWiFi_80\n",
  "HackedWiFi_81\n",
  "HackedWiFi_82\n",
  "HackedWiFi_83\n",
  "HackedWiFi_84\n",
  "HackedWiFi_85\n",
  "HackedWiFi_86\n",
  "HackedWiFi_87\n",
  "HackedWiFi_88\n",
  "HackedWiFi_89\n",
  "HackedWiFi_90\n",
  "HackedWiFi_91\n",
  "HackedWiFi_92\n",
  "HackedWiFi_93\n",
  "HackedWiFi_94\n",
  "HackedWiFi_95\n",
  "HackedWiFi_96\n",
  "HackedWiFi_97\n",
  "HackedWiFi_98\n",
  "HackedWiFi_99\n",
  "HackedWiFi_100\n",
  "HackedWiFi_101\n",
  "HackedWiFi_102\n",
  "HackedWiFi_103\n",
  "HackedWiFi_104\n",
  "HackedWiFi_105\n",
  "HackedWiFi_106\n",
  "HackedWiFi_107\n",
  "HackedWiFi_108\n",
  "HackedWiFi_109\n",
  "HackedWiFi_110\n",
  "HackedWiFi_111\n",
  "HackedWiFi_112\n",
  "HackedWiFi_113\n",
  "HackedWiFi_114\n",
  "HackedWiFi_115\n",
  "HackedWiFi_116\n",
  "HackedWiFi_117\n",
  "HackedWiFi_118\n",
  "HackedWiFi_119\n",
  "HackedWiFi_120\n",
  "HackedWiFi_121\n",
  "HackedWiFi_122\n",
  "HackedWiFi_123\n",
  "HackedWiFi_124\n",
  "HackedWiFi_125\n",
  "HackedWiFi_126\n",
  "HackedWiFi_127\n",
  "HackedWiFi_128\n",
  "HackedWiFi_129\n",
  "HackedWiFi_130\n",
  "HackedWiFi_131\n",
  "HackedWiFi_132\n",
  "HackedWiFi_133\n",
  "HackedWiFi_134\n",
  "HackedWiFi_135\n",
  "HackedWiFi_136\n",
  "HackedWiFi_137\n",
  "HackedWiFi_138\n",
  "HackedWiFi_139\n",
  "HackedWiFi_140\n",
  "HackedWiFi_141\n",
  "HackedWiFi_142\n",
  "HackedWiFi_143\n",
  "HackedWiFi_144\n",
  "HackedWiFi_145\n",
  "HackedWiFi_146\n",
  "HackedWiFi_147\n",
  "HackedWiFi_148\n",
  "HackedWiFi_149\n",
  "HackedWiFi_150\n",
  "HackedWiFi_151\n",
  "HackedWiFi_152\n",
  "HackedWiFi_153\n",
  "HackedWiFi_154\n",
  "HackedWiFi_155\n",
  "HackedWiFi_156\n",
  "HackedWiFi_157\n",
  "HackedWiFi_158\n",
  "HackedWiFi_159\n",
  "HackedWiFi_160\n",
  "HackedWiFi_161\n",
  "HackedWiFi_162\n",
  "HackedWiFi_163\n",
  "HackedWiFi_164\n",
  "HackedWiFi_165\n",
  "HackedWiFi_166\n",
  "HackedWiFi_167\n",
  "HackedWiFi_168\n",
  "HackedWiFi_169\n",
  "HackedWiFi_170\n",
  "HackedWiFi_171\n",
  "HackedWiFi_172\n",
  "HackedWiFi_173\n",
  "HackedWiFi_174\n",
  "HackedWiFi_175\n",
  "HackedWiFi_176\n",
  "HackedWiFi_177\n",
  "HackedWiFi_178\n",
  "HackedWiFi_179\n",
  "HackedWiFi_180\n",
  "HackedWiFi_181\n",
  "HackedWiFi_182\n",
  "HackedWiFi_183\n",
  "HackedWiFi_184\n",
  "HackedWiFi_185\n",
  "HackedWiFi_186\n",
  "HackedWiFi_187\n",
  "HackedWiFi_188\n",
  "HackedWiFi_189\n",
  "HackedWiFi_190\n",
  "HackedWiFi_191\n",
  "HackedWiFi_192\n",
  "HackedWiFi_193\n",
  "HackedWiFi_194\n",
  "HackedWiFi_195\n",
  "HackedWiFi_196\n",
  "HackedWiFi_197\n",
  "HackedWiFi_198\n",
  "HackedWiFi_199\n",
  "HackedWiFi_200\n",
  "HackedWiFi_201\n",
  "HackedWiFi_202\n",
  "HackedWiFi_203\n",
  "HackedWiFi_204\n",
  "HackedWiFi_205\n",
  "HackedWiFi_206\n",
  "HackedWiFi_207\n",
  "HackedWiFi_208\n",
  "HackedWiFi_209\n",
  "HackedWiFi_210\n",
  "HackedWiFi_211\n",
  "HackedWiFi_212\n",
  "HackedWiFi_213\n",
  "HackedWiFi_214\n",
  "HackedWiFi_215\n",
  "HackedWiFi_216\n",
  "HackedWiFi_217\n",
  "HackedWiFi_218\n",
  "HackedWiFi_219\n",
  "HackedWiFi_220\n",
  "HackedWiFi_221\n",
  "HackedWiFi_222\n",
  "HackedWiFi_223\n",
  "HackedWiFi_224\n",
  "HackedWiFi_225\n",
  "HackedWiFi_226\n",
  "HackedWiFi_227\n",
  "HackedWiFi_228\n",
  "HackedWiFi_229\n",
  "HackedWiFi_230\n",
  "HackedWiFi_231\n",
  "HackedWiFi_232\n",
  "HackedWiFi_233\n",
  "HackedWiFi_234\n",
  "HackedWiFi_235\n",
  "HackedWiFi_236\n",
  "HackedWiFi_237\n",
  "HackedWiFi_238\n",
  "HackedWiFi_239\n",
  "HackedWiFi_240\n",
  "HackedWiFi_241\n",
  "HackedWiFi_242\n",
  "HackedWiFi_243\n",
  "HackedWiFi_244\n",
  "HackedWiFi_245\n",
  "HackedWiFi_246\n",
  "HackedWiFi_247\n",
  "HackedWiFi_248\n",
  "HackedWiFi_249\n",
  "HackedWiFi_250\n"
};


// Create a bare packet
uint8_t packet[128] = { 0x80, 0x00, 0x00, 0x00, //Frame Control, Duration
                /*4*/   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, //Destination address 
                /*10*/  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, //Source address - overwritten later
                /*16*/  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, //BSSID - overwritten to the same as the source address
                /*22*/  0xc0, 0x6c, //Seq-ctl
                /*24*/  0x83, 0x51, 0xf7, 0x8f, 0x0f, 0x00, 0x00, 0x00, //timestamp - the number of microseconds the AP has been active
                /*32*/  0x64, 0x00, //Beacon interval
                /*34*/  0x01, 0x04, //Capability info
                /* SSID */
                /*36*/  0x00
};

// Function to broadcast the SSID
void broadcastSetSSID(const char* ESSID) {

  // Set a random channel
  int set_channel = random(1,12); 
  esp_wifi_set_channel(set_channel, WIFI_SECOND_CHAN_NONE);
  delay(1);

  // Randomize SRC MAC
  packet[10] = packet[16] = random(256);
  packet[11] = packet[17] = random(256);
  packet[12] = packet[18] = random(256);
  packet[13] = packet[19] = random(256);
  packet[14] = packet[20] = random(256);
  packet[15] = packet[21] = random(256);

  // Get the length of the SSID
  int ssidLen = strlen(ESSID);
  int fullLen = ssidLen;
  packet[37] = fullLen;

  // Insert my tag
  for(int i = 0; i < ssidLen; i++) {
    packet[38 + i] = ESSID[i];
  }

  /////////////////////////////

  packet[50 + fullLen] = set_channel;

  uint8_t postSSID[13] = {0x01, 0x08, 0x82, 0x84, 0x8b, 0x96, 0x24, 0x30, 0x48, 0x6c, //supported rate
                      0x03, 0x01, 0x04 /*DSSS (Current Channel)*/ };

  // Add everything that goes after the SSID
  for(int i = 0; i < 12; i++) {
    packet[38 + fullLen + i] = postSSID[i];
  }

  digitalWrite(LED_BUILTIN,HIGH);
  delay(200);
  // Transmit the packet
  esp_wifi_80211_tx(WIFI_IF_STA, packet, sizeof(packet), false);
  digitalWrite(LED_BUILTIN,LOW);

}

void setup() {

  // Configure the ESP32
  esp_wifi_start();
  WiFi.mode(WIFI_MODE_STA);
  esp_wifi_set_promiscuous(true);
  esp_wifi_set_max_tx_power(82);
  pinMode(LED_BUILTIN,OUTPUT);

}

void loop() {

  // Get the current time
  currentTime = millis();

  // Send out SSIDs if the delay has been long enough
  if (currentTime - attackTime > attackDelay) {

    // Send the SSID
    broadcastSetSSID(ssids[currentID]);

    // Iterate over the SSIDs
    if (currentID >= numIDs - 1) {
      currentID = 0;
    } else {
      currentID++;
    }

    // Update the time
    attackTime = currentTime;

  }

}