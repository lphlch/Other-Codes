module OnlyMyRailGun (input iClk,
                      input iReset_n,
                      input iEnable,
                      input [1:0] iControl_Progress,
                      input [2:0] iControl_Speed,
                      input [2:0] iControl_Freq,
                      output [7:0] oProgress,
                      output reg [7:0] oFreq);
    
    parameter default_notes_speed = 135*4*4;    //notes every minutes = meter speed * notes per meter
    parameter notes_total = 600;
    reg [20:0] note,count,notes_speed;
    reg[7:0] freq,notes_offset;

    always @(iControl_Speed) begin  //0.25 ~ 3 X speed
        if(!iReset_n || !iEnable) begin
            notes_speed <= default_notes_speed;
        end
        else begin
            case (iControl_Speed)
                1: notes_speed <= default_notes_speed*0.25; 
                2: notes_speed <= default_notes_speed*0.5;
                3: notes_speed <= default_notes_speed*0.75;
                4: notes_speed <= default_notes_speed;
                5: notes_speed <= default_notes_speed*1.5;
                6: notes_speed <= default_notes_speed*2;
                7: notes_speed <= default_notes_speed*3;
                default: notes_speed <= default_notes_speed;
            endcase
        end
    end

    always @(iControl_Freq) begin   //-3 ~ +3 Freq
        if(!iReset_n || !iEnable) begin
            oFreq <= freq;
        end
        else begin
            case (iControl_Freq)
                1: oFreq <= freq-3;
                2: oFreq <= freq-2;
                3: oFreq <= freq-1;
                4: oFreq <= freq;
                5: oFreq <= freq+1;
                6: oFreq <= freq+2;
                7: oFreq <= freq+3;
                default: oFreq <= freq;
            endcase
        end

    end

    always @(iControl_Progress) begin   // +5 -5 notes
        if(!iReset_n || !iEnable) begin
            notes_offset <= 0;
        end
        else begin
            if(notes_offset!=0) begin
                notes_offset <= 0;
            end
            else begin
                case (iControl_Progress)
                    2'b00: notes_offset <= 0;
                    2'b01: notes_offset <= 5;
                    2'b10: notes_offset <= -5;
                    default: notes_offset <= 0;
                endcase
            end
        end
    end

    always @(posedge iClk or negedge iReset_n) begin
        
        if (!iReset_n) begin
            freq <= 0;
            note  <= 0;
            count <= 0;
        end
        else begin
            if (iEnable) begin
                if (count == 60*3810000/notes_speed) begin   //count to 0.15s
                    count <= 0;
                    note <= note+1+notes_offset;
                end
                else begin
                    count <= count+1;
                end

                if(note==notes_total) begin
                    note <= 0;
                end
                
                case (note)
                    0: freq <= 100;
                    1: freq <= 100;
                    2: freq <= 100;
                    3: freq <= 100;
                    4: freq <= 41;
                    5: freq <= 41;
                    6: freq <= 41;
                    7: freq <= 100;
                    8: freq <= 41;
                    9: freq <= 41;
                    10: freq <= 41;
                    11: freq <= 100;
                    12: freq <= 39;
                    13: freq <= 100;
                    14: freq <= 41;
                    15: freq <= 100;
                    16: freq <= 100;
                    17: freq <= 100;
                    18: freq <= 100;
                    19: freq <= 100;
                    20: freq <= 41;
                    21: freq <= 41;
                    22: freq <= 41;
                    23: freq <= 100;
                    24: freq <= 39;
                    25: freq <= 39;
                    26: freq <= 39;
                    27: freq <= 100;
                    28: freq <= 39;
                    29: freq <= 100;
                    30: freq <= 41;
                    31: freq <= 100;
                    32: freq <= 100;
                    33: freq <= 100;
                    34: freq <= 100;
                    35: freq <= 100;
                    36: freq <= 41;
                    37: freq <= 41;
                    38: freq <= 41;
                    39: freq <= 100;
                    40: freq <= 41;
                    41: freq <= 41;
                    42: freq <= 41;
                    43: freq <= 100;
                    44: freq <= 39;
                    45: freq <= 100;
                    46: freq <= 41;
                    47: freq <= 100;
                    48: freq <= 100;
                    49: freq <= 100;
                    50: freq <= 100;
                    51: freq <= 100;
                    52: freq <= 41;
                    53: freq <= 41;
                    54: freq <= 41;
                    55: freq <= 100;
                    56: freq <= 39;
                    57: freq <= 39;
                    58: freq <= 39;
                    59: freq <= 100;
                    60: freq <= 39;
                    61: freq <= 100;
                    62: freq <= 41;
                    63: freq <= 100;
                    64: freq <= 100;
                    65: freq <= 100;
                    66: freq <= 100;
                    67: freq <= 100;
                    68: freq <= 41;
                    69: freq <= 41;
                    70: freq <= 41;
                    71: freq <= 100;
                    72: freq <= 41;
                    73: freq <= 41;
                    74: freq <= 41;
                    75: freq <= 100;
                    76: freq <= 39;
                    77: freq <= 100;
                    78: freq <= 41;
                    79: freq <= 100;
                    80: freq <= 100;
                    81: freq <= 100;
                    82: freq <= 100;
                    83: freq <= 100;
                    84: freq <= 41;
                    85: freq <= 41;
                    86: freq <= 41;
                    87: freq <= 100;
                    88: freq <= 39;
                    89: freq <= 39;
                    90: freq <= 39;
                    91: freq <= 100;
                    92: freq <= 39;
                    93: freq <= 100;
                    94: freq <= 41;
                    95: freq <= 100;
                    96: freq <= 100;
                    97: freq <= 100;
                    98: freq <= 100;
                    99: freq <= 100;
                    100: freq <= 41;
                    101: freq <= 41;
                    102: freq <= 41;
                    103: freq <= 100;
                    104: freq <= 41;
                    105: freq <= 41;
                    106: freq <= 41;
                    107: freq <= 100;
                    108: freq <= 39;
                    109: freq <= 100;
                    110: freq <= 41;
                    111: freq <= 100;
                    112: freq <= 100;
                    113: freq <= 100;
                    114: freq <= 100;
                    115: freq <= 100;
                    116: freq <= 41;
                    117: freq <= 41;
                    118: freq <= 41;
                    119: freq <= 100;
                    120: freq <= 39;
                    121: freq <= 39;
                    122: freq <= 39;
                    123: freq <= 100;
                    124: freq <= 39;
                    125: freq <= 100;
                    126: freq <= 41;
                    127: freq <= 100;
                    128: freq <= 100;
                    129: freq <= 100;
                    130: freq <= 100;
                    131: freq <= 100;
                    132: freq <= 41;
                    133: freq <= 41;
                    134: freq <= 41;
                    135: freq <= 100;
                    136: freq <= 41;
                    137: freq <= 41;
                    138: freq <= 41;
                    139: freq <= 100;
                    140: freq <= 39;
                    141: freq <= 100;
                    142: freq <= 41;
                    143: freq <= 100;
                    144: freq <= 100;
                    145: freq <= 100;
                    146: freq <= 100;
                    147: freq <= 100;
                    148: freq <= 41;
                    149: freq <= 41;
                    150: freq <= 41;
                    151: freq <= 100;
                    152: freq <= 39;
                    153: freq <= 39;
                    154: freq <= 39;
                    155: freq <= 100;
                    156: freq <= 39;
                    157: freq <= 100;
                    158: freq <= 41;
                    159: freq <= 100;
                    160: freq <= 100;
                    161: freq <= 100;
                    162: freq <= 100;
                    163: freq <= 100;
                    164: freq <= 41;
                    165: freq <= 41;
                    166: freq <= 41;
                    167: freq <= 100;
                    168: freq <= 41;
                    169: freq <= 41;
                    170: freq <= 41;
                    171: freq <= 100;
                    172: freq <= 39;
                    173: freq <= 100;
                    174: freq <= 41;
                    175: freq <= 100;
                    176: freq <= 100;
                    177: freq <= 100;
                    178: freq <= 100;
                    179: freq <= 100;
                    180: freq <= 41;
                    181: freq <= 41;
                    182: freq <= 41;
                    183: freq <= 100;
                    184: freq <= 39;
                    185: freq <= 39;
                    186: freq <= 39;
                    187: freq <= 100;
                    188: freq <= 39;
                    189: freq <= 100;
                    190: freq <= 41;
                    191: freq <= 100;
                    192: freq <= 100;
                    193: freq <= 100;
                    194: freq <= 100;
                    195: freq <= 100;
                    196: freq <= 41;
                    197: freq <= 41;
                    198: freq <= 41;
                    199: freq <= 100;
                    200: freq <= 41;
                    201: freq <= 41;
                    202: freq <= 41;
                    203: freq <= 100;
                    204: freq <= 39;
                    205: freq <= 100;
                    206: freq <= 41;
                    207: freq <= 100;
                    208: freq <= 100;
                    209: freq <= 100;
                    210: freq <= 100;
                    211: freq <= 100;
                    212: freq <= 41;
                    213: freq <= 41;
                    214: freq <= 41;
                    215: freq <= 100;
                    216: freq <= 39;
                    217: freq <= 39;
                    218: freq <= 39;
                    219: freq <= 100;
                    220: freq <= 39;
                    221: freq <= 100;
                    222: freq <= 41;
                    223: freq <= 100;

                    //main
                    225: freq <= 100;
                    226: freq <= 100;
                    227: freq <= 100;
                    228: freq <= 41;
                    229: freq <= 41;
                    230: freq <= 41;
                    231: freq <= 100;
                    232: freq <= 41;
                    233: freq <= 41;
                    234: freq <= 41;
                    235: freq <= 100;
                    236: freq <= 39;
                    237: freq <= 100;
                    238: freq <= 41;
                    239: freq <= 100;
                    240: freq <= 100;
                    241: freq <= 100;
                    242: freq <= 100;
                    243: freq <= 100;
                    244: freq <= 56;
                    245: freq <= 56;
                    246: freq <= 56;
                    247: freq <= 100;
                    248: freq <= 55;
                    249: freq <= 55;
                    250: freq <= 55;
                    251: freq <= 100;
                    252: freq <= 51;
                    253: freq <= 51;
                    254: freq <= 51;
                    255: freq <= 100;

                    257,258,259,260: freq <= 51;
                    262,264,265,266,267: freq <= 53;

                    268,269,270,271: freq <= 51;

                    273,274,275,276: freq <= 51;
                    278,280,281,282,283: freq <= 53;

                    285,286,287,288: freq <= 51;


                    290,291,292,293: freq <= 51;
                    295,297,298,299,300: freq <= 53;

                    302,303,304,305: freq <= 53;

                    307,308,309,310: freq <= 53;
                    312,313,314,315: freq <= 55;

                    317,318,319,320: freq <= 56;
                    322,323,324,325: freq <= 58;


                    327,328,329,330,331,332,333,334,335: freq <= 55;

                    337,338,339,340,341,342,343,344,345: freq <= 51;

                    347,348,349,350,351,352,353,354,355: freq <= 61;

                    357,358,359,360,361,362,363,364: freq <= 58;

                    366: freq <= 58;
                    367: freq <= 58;
                    368: freq <= 58;
                    369: freq <= 58;
                    370: freq <= 58;
                    371: freq <= 100;
                    372: freq <= 58;
                    373: freq <= 58;
                    374: freq <= 58;
                    375: freq <= 100;
                    376: freq <= 60;
                    377: freq <= 60;
                    378: freq <= 60;
                    379: freq <= 60;
                    380: freq <= 100;
                    381: freq <= 100;
                    382: freq <= 100;
                    383: freq <= 100;
                    384: freq <= 100;
                    385: freq <= 56;
                    386: freq <= 56;
                    387: freq <= 56;
                    388: freq <= 56;
                    389: freq <= 100;
                    390: freq <= 55;
                    391: freq <= 55;
                    392: freq <= 55;
                    393: freq <= 55;
                    394: freq <= 100;
                    395: freq <= 51;
                    396: freq <= 51;
                    397: freq <= 51;
                    398: freq <= 51;

                    //13
                    400: freq <= 51;
                    401: freq <= 51;
                    402: freq <= 51;
                    403: freq <= 51;
                    404: freq <= 100;
                    405: freq <= 53;
                    406: freq <= 100;
                    407: freq <= 53;
                    408: freq <= 53;
                    409: freq <= 53;
                    410: freq <= 100;
                    411: freq <= 51;
                    412: freq <= 51;
                    413: freq <= 51;
                    414: freq <= 51;
                    415: freq <= 100;
                    416: freq <= 51;
                    417: freq <= 51;
                    418: freq <= 51;
                    419: freq <= 51;
                    420: freq <= 100;
                    421: freq <= 53;
                    422: freq <= 100;
                    423: freq <= 53;
                    424: freq <= 53;
                    425: freq <= 53;
                    426: freq <= 100;
                    427: freq <= 51;
                    428: freq <= 51;
                    429: freq <= 51;
                    430: freq <= 51;

                    //14
                    432: freq <= 51;
                    433: freq <= 51;
                    434: freq <= 51;
                    435: freq <= 51;
                    436: freq <= 100;
                    437: freq <= 53;
                    438: freq <= 100;
                    439: freq <= 53;
                    440: freq <= 53;
                    441: freq <= 53;
                    442: freq <= 100;
                    443: freq <= 53;
                    444: freq <= 53;
                    445: freq <= 53;
                    446: freq <= 53;
                    447: freq <= 100;
                    448: freq <= 53;
                    449: freq <= 53;
                    450: freq <= 53;
                    451: freq <= 53;
                    452: freq <= 100;
                    453: freq <= 55;
                    454: freq <= 55;
                    455: freq <= 55;
                    456: freq <= 55;
                    457: freq <= 100;
                    458: freq <= 56;
                    459: freq <= 56;
                    460: freq <= 56;
                    461: freq <= 56;
                    462: freq <= 100;
                    463: freq <= 58;
                    464: freq <= 58;
                    465: freq <= 58;
                    466: freq <= 58;

                    //15
                    468: freq <= 53;
                    469: freq <= 53;
                    470: freq <= 53;
                    471: freq <= 53;
                    472: freq <= 53;
                    473: freq <= 53;
                    474: freq <= 53;
                    475: freq <= 53;
                    476: freq <= 53;
                    477: freq <= 53;
                    478: freq <= 53;
                    479: freq <= 53;
                    480: freq <= 53;
                    481: freq <= 53;
                    482: freq <= 53;
                    483: freq <= 53;
                    484: freq <= 100;
                    485: freq <= 53;
                    486: freq <= 53;
                    487: freq <= 53;
                    488: freq <= 53;
                    489: freq <= 100;
                    490: freq <= 55;
                    491: freq <= 55;
                    492: freq <= 55;
                    493: freq <= 55;
                    494: freq <= 100;
                    495: freq <= 56;
                    496: freq <= 56;
                    497: freq <= 56;
                    498: freq <= 56;
                    499: freq <= 100;
                    500: freq <= 58;
                    501: freq <= 58;
                    502: freq <= 58;
                    503: freq <= 58;

                    //16
                    505: freq <= 55;
                    506: freq <= 55;
                    507: freq <= 55;
                    508: freq <= 55;
                    509: freq <= 55;
                    510: freq <= 55;
                    511: freq <= 55;
                    512: freq <= 55;
                    513: freq <= 100;
                    514: freq <= 51;
                    515: freq <= 51;
                    516: freq <= 51;
                    517: freq <= 51;
                    518: freq <= 51;
                    519: freq <= 51;
                    520: freq <= 51;
                    521: freq <= 51;
                    522: freq <= 100;
                    523: freq <= 48;
                    524: freq <= 48;
                    525: freq <= 48;
                    526: freq <= 48;
                    527: freq <= 48;
                    528: freq <= 48;
                    529: freq <= 48;
                    530: freq <= 48;
                    531: freq <= 100;
                    532: freq <= 51;
                    533: freq <= 51;
                    534: freq <= 51;
                    535: freq <= 51;
                    536: freq <= 51;
                    537: freq <= 51;
                    538: freq <= 51;
                    539: freq <= 51;

                    //17
                    541: freq <= 51;
                    542: freq <= 51;
                    543: freq <= 51;
                    544: freq <= 51;
                    545: freq <= 100;
                    546: freq <= 53;
                    547: freq <= 100;
                    548: freq <= 53;
                    549: freq <= 53;
                    550: freq <= 53;
                    551: freq <= 100;
                    552: freq <= 56;
                    553: freq <= 56;
                    554: freq <= 56;
                    555: freq <= 56;
                    556: freq <= 100;
                    557: freq <= 55;
                    558: freq <= 55;
                    559: freq <= 55;
                    560: freq <= 55;
                    561: freq <= 100;
                    562: freq <= 51;
                    563: freq <= 100;
                    564: freq <= 48;
                    565: freq <= 48;
                    566: freq <= 48;
                    567: freq <= 100;
                    568: freq <= 51;
                    569: freq <= 51;
                    570: freq <= 51;
                    571: freq <= 51;

                    //18
                    573: freq <= 51;
                    574: freq <= 51;
                    575: freq <= 51;
                    576: freq <= 51;
                    577: freq <= 100;
                    578: freq <= 53;
                    579: freq <= 100;
                    580: freq <= 53;
                    581: freq <= 53;
                    582: freq <= 53;
                    583: freq <= 53;
                    584: freq <= 53;
                    585: freq <= 53;
                    default: freq<=100;
                endcase
                
                
                
                
                
                
            end
            else begin
                count <= 0;
                note  <= 0;
            end
        end
    end



    assign oProgress=((iReset_n)?0:(note/notes_total));
endmodule
