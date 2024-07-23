/*
 * Copyright (c) 2021 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/outputs.h>

#define APT 0
#define NUM 1
#define NAV 2
#define SYM 3
#define FUN 4
#define BTC 5

// &lt {
//     quick_tap_ms = <200>;
// };

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};

/ {
    macros {
        macro_sch: macro_sch {
            label = "Macro_SCH";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = <&macro_tap &kp S &kp C &kp H>;
        };
        macro_shifted_sch: macro_shifted_sch {
            label = "Macro_Sch";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = <&macro_tap &kp LS(S) &kp C &kp H>;
        };
    };
};


#define COMBO(NAME, BINDINGS, KEYPOS) \
combo_##NAME { \
    timeout-ms = <20>; \
    bindings = <BINDINGS>; \
    key-positions = <KEYPOS>; \
};

//  ___________________________________       ___________________________________
// |  0  |  1  |  2  |  3  |  4  |     |     |     |    5 |   6 |   7 |   8 |  9  |
// | 10  | 11  | 12  | 13  | 14  |     |     |     |   15 |  16 |  17 |  18 | 19  |
// | 20  | 21  | 22  | 23  | 24  | ROT |     | ROT |   25 |  26 |  27 |  28 | 29  |
// |                         30  | 31  |     |  32 |  33                         |
//  -----------------------------------       -----------------------------------

/ {
    combos {
        compatible = "zmk,combos";
/* usually on base layer */
        COMBO(q, &kp Q, 2 3)
        COMBO(z, &kp Z, 21 22)
        COMBO(v, &kp V, 1 2)
        COMBO(sch, &macro_sch, 1 3)
        COMBO(slash, &kp SLASH, 27 28)
        COMBO(dash, &kp MINUS, 26 27)
        COMBO(enter, &kp ENTER, 26 28)
        COMBO(esc, &kp ESC, 22 23)
/* parentheticals */
        COMBO(lbrc, &kp LBRC, 1 11)
        COMBO(lbkt, &kp LBKT, 2 12)
        COMBO(lpar, &kp LPAR, 3 13)
        COMBO(lt, &kp LT, 4 14)
        COMBO(gt, &kp GT, 5 15)
        COMBO(rpar, &kp RPAR, 6 16)
        COMBO(rbkt, &kp RBKT, 7 17)
        COMBO(rbrc, &kp RBRC, 8 18)
/* caps */
        COMBO(caps, &caps_word, 13 16)
        COMBO(capslock, &kp CAPSLOCK, 1 8)
/* deletion */
        COMBO(bspc, &kp BSPC, 6 7)
        COMBO(del, &kp DEL, 7 8)
        COMBO(delword, &kp LC(BSPC), 6 8)
/* alternative shifting */
        COMBO(Sq, &kp LS(Q), 2 3 31)
        COMBO(Sz, &kp LS(Z), 21 22 31)
        COMBO(Sv, &kp LS(V), 1 2 31)
        COMBO(Ssch, &macro_shifted_sch, 1 3 31)
        COMBO(Sw, &kp LS(W), 1 31)
        COMBO(Sf, &kp LS(F), 2 31)
        COMBO(Sp, &kp LS(P), 3 31)
        COMBO(Sb, &kp LS(B), 4 31)
        COMBO(Sj, &kp LS(J), 5 32)
        COMBO(Sl, &kp LS(L), 6 32)
        COMBO(Su, &kp LS(U), 7 32)
        COMBO(Sy, &kp LS(Y), 8 32)
        COMBO(Sr, &kp LS(R), 10 31)
        COMBO(Ss, &kp LS(S), 11 31)
        COMBO(St, &kp LS(T), 12 31)
        COMBO(Sh, &kp LS(H), 13 31)
        COMBO(Sk, &kp LS(K), 14 31)
        COMBO(Sx, &kp LS(X), 15 32)
        COMBO(Sn, &kp LS(N), 16 32)
        COMBO(Sa, &kp LS(A), 17 32)
        COMBO(Si, &kp LS(I), 18 32)
        COMBO(So, &kp LS(O), 19 32)
        COMBO(Sc, &kp LS(C), 21 31)
        COMBO(Sg, &kp LS(G), 22 31)
        COMBO(Sd, &kp LS(D), 23 31)
        COMBO(Sm, &kp LS(M), 26 32)
        COMBO(Scomma, &kp SEMI, 27 32)
        COMBO(Sdot, &kp COLON, 28 32)
        COMBO(Se, &kp LS(E), 16 17 32)
    };
};

/ {
    behaviors {
        hl: homerow_mods_left {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods left";
            #binding-cells = <2>;
            flavor = "tap-preferred";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <5 6 7 8 9 15 16 17 18 19 25 26 27 28 29 32 33>;
        };

        hr: homerow_mods_right {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods right";
            #binding-cells = <2>;
            flavor = "tap-preferred";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <0 1 2 3 4 10 11 12 13 14 20 21 22 23 24 30 31>;
        };

        my_lt: my_layer_taps {
            compatible = "zmk,behavior-hold-tap";
            label = "my layer taps";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&mo &kp>, <&kp>;
            // non-thumb keys
            // hold-trigger-key-positions = <0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23>;
        };

        dotcol: dot_colon {
            compatible = "zmk,behavior-mod-morph";
            label = "DOT_COL";
            #binding-cells = <0>;
            bindings = <&kp DOT>, <&kp COLON>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
        comsem: comma_semicolon {
            compatible = "zmk,behavior-mod-morph";
            label = "COM_SEM";
            #binding-cells = <0>;
            bindings = <&kp COMMA>, <&kp SEMI>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
    };
};
