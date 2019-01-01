/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:03:50 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 18:47:08 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X_KEYS_H
# define X_KEYS_H

# define X_KEYPRESS 2
# define X_BUTTONPRESS 4
# define X_MOTIONNOTIFY 6
# define X_DESTROYNOTIFY 17

# define X_NOEVENT_MASK 0L
# define X_KEYPRESS_MASK (1L << 0)
# define X_KEYRELEASE_MASK (1L << 1)
# define X_BUTTONPRESS_MASK (1L << 2)
# define X_BUTTONRELEASE_MASK (1L << 3)
# define X_ENTERWINDOW_MASK (1L << 4)
# define X_LEAVEWINDOW_MASK (1L << 5)
# define X_POINTERMOTION_MASK (1L << 6)
# define X_POINTERMOTIONHINT_MASK (1L << 7)
# define X_BUTTON1MOTION_MASK (1L << 8)
# define X_BUTTON2MOTION_MASK (1L << 9)
# define X_BUTTON3MOTION_MASK (1L << 10)
# define X_BUTTON4MOTION_MASK (1L << 11)
# define X_BUTTON5MOTION_MASK (1L << 12)
# define X_BUTTONMOTION_MASK (1L << 13)
# define X_KEYMAPSTATE_MASK (1L << 14)
# define X_EXPOSUREMASK_MASK (1L << 15)
# define X_VISIBILITYCHANGE_MASK (1L << 16)
# define X_STRUCTURENOTIFY_MASK (1L << 17)
# define X_RESIZEREDIRECT_MASK (1L << 18)
# define X_SUBSTRUCTURENOTIFY_MASK (1L << 19)
# define X_SUBSTRUCTUREREDIRECT_MASK (1L << 20)
# define X_FOCUSCHANGE_MASK (1L << 21)
# define X_PROPERTYCHANGE_MASK (1L << 22)
# define X_COLORMAPCHANGE_MASK (1L << 23)
# define X_OWNERGRABBUTTON_MASK (1L << 24)

# define X_KEY_A 0
# define X_KEY_S 1
# define X_KEY_D 2
# define X_KEY_F 3
# define X_KEY_H 4
# define X_KEY_G 5
# define X_KEY_Z 6
# define X_KEY_X 7
# define X_KEY_C 8
# define X_KEY_V 9
# define X_KEY_B 11
# define X_KEY_Q 12
# define X_KEY_W 13
# define X_KEY_E 14
# define X_KEY_R 15
# define X_KEY_Y 16
# define X_KEY_T 17
# define X_KEY_1 18
# define X_KEY_2 19
# define X_KEY_3 20
# define X_KEY_4 21
# define X_KEY_6 22
# define X_KEY_5 23
# define X_KEY_EQUAL 24
# define X_KEY_9 25
# define X_KEY_7 26
# define X_KEY_MINUS 27
# define X_KEY_8 28
# define X_KEY_0 29
# define X_KEY_O 31
# define X_KEY_U 32
# define X_KEY_I 34
# define X_KEY_P 35
# define X_KEY_ENTER 36
# define X_KEY_L 37
# define X_KEY_J 38
# define X_KEY_K 40
# define X_KEY_N 45
# define X_KEY_M 46
# define X_KEY_TAB 48
# define X_KEY_SPACE 49
# define X_KEY_BACKTICK 50
# define X_KEY_BACKSPACE 51
# define X_KEY_ESCAPE 53
# define X_KEY_DEL 117
# define X_KEY_L_ARROW 123
# define X_KEY_R_ARROW 124
# define X_KEY_U_ARROW 126
# define X_KEY_D_ARROW 125
# define X_KEY_L_CTRL 256
# define X_KEY_L_SHIFT 257
# define X_KEY_R_SHIFT 258
# define X_KEY_L_ALT 259
# define X_KEY_R_ALT 260
# define X_KEY_R_CTRL 269

# define X_SCROLL_DOWN 4
# define X_SCROLL_UP 5

#endif
