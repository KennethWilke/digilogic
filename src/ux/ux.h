/*
   Copyright 2024 Ryan "rj45" Sanche

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef UX_H
#define UX_H

#include "handmade_math.h"

#include "autoroute/autoroute.h"
#include "core/core.h"
#include "view/view.h"

typedef enum KeyCodes {
  KEYCODE_INVALID = 0,
  KEYCODE_SPACE = 32,
  KEYCODE_APOSTROPHE = 39, /* ' */
  KEYCODE_COMMA = 44,      /* , */
  KEYCODE_MINUS = 45,      /* - */
  KEYCODE_PERIOD = 46,     /* . */
  KEYCODE_SLASH = 47,      /* / */
  KEYCODE_0 = 48,
  KEYCODE_1 = 49,
  KEYCODE_2 = 50,
  KEYCODE_3 = 51,
  KEYCODE_4 = 52,
  KEYCODE_5 = 53,
  KEYCODE_6 = 54,
  KEYCODE_7 = 55,
  KEYCODE_8 = 56,
  KEYCODE_9 = 57,
  KEYCODE_SEMICOLON = 59, /* ; */
  KEYCODE_EQUAL = 61,     /* = */
  KEYCODE_A = 65,
  KEYCODE_B = 66,
  KEYCODE_C = 67,
  KEYCODE_D = 68,
  KEYCODE_E = 69,
  KEYCODE_F = 70,
  KEYCODE_G = 71,
  KEYCODE_H = 72,
  KEYCODE_I = 73,
  KEYCODE_J = 74,
  KEYCODE_K = 75,
  KEYCODE_L = 76,
  KEYCODE_M = 77,
  KEYCODE_N = 78,
  KEYCODE_O = 79,
  KEYCODE_P = 80,
  KEYCODE_Q = 81,
  KEYCODE_R = 82,
  KEYCODE_S = 83,
  KEYCODE_T = 84,
  KEYCODE_U = 85,
  KEYCODE_V = 86,
  KEYCODE_W = 87,
  KEYCODE_X = 88,
  KEYCODE_Y = 89,
  KEYCODE_Z = 90,
  KEYCODE_LEFT_BRACKET = 91,  /* [ */
  KEYCODE_BACKSLASH = 92,     /* \ */
  KEYCODE_RIGHT_BRACKET = 93, /* ] */
  KEYCODE_GRAVE_ACCENT = 96,  /* ` */
  KEYCODE_WORLD_1 = 161,      /* non-US #1 */
  KEYCODE_WORLD_2 = 162,      /* non-US #2 */
  KEYCODE_ESCAPE = 256,
  KEYCODE_ENTER = 257,
  KEYCODE_TAB = 258,
  KEYCODE_BACKSPACE = 259,
  KEYCODE_INSERT = 260,
  KEYCODE_DELETE = 261,
  KEYCODE_RIGHT = 262,
  KEYCODE_LEFT = 263,
  KEYCODE_DOWN = 264,
  KEYCODE_UP = 265,
  KEYCODE_PAGE_UP = 266,
  KEYCODE_PAGE_DOWN = 267,
  KEYCODE_HOME = 268,
  KEYCODE_END = 269,
  KEYCODE_CAPS_LOCK = 280,
  KEYCODE_SCROLL_LOCK = 281,
  KEYCODE_NUM_LOCK = 282,
  KEYCODE_PRINT_SCREEN = 283,
  KEYCODE_PAUSE = 284,
  KEYCODE_F1 = 290,
  KEYCODE_F2 = 291,
  KEYCODE_F3 = 292,
  KEYCODE_F4 = 293,
  KEYCODE_F5 = 294,
  KEYCODE_F6 = 295,
  KEYCODE_F7 = 296,
  KEYCODE_F8 = 297,
  KEYCODE_F9 = 298,
  KEYCODE_F10 = 299,
  KEYCODE_F11 = 300,
  KEYCODE_F12 = 301,
  KEYCODE_F13 = 302,
  KEYCODE_F14 = 303,
  KEYCODE_F15 = 304,
  KEYCODE_F16 = 305,
  KEYCODE_F17 = 306,
  KEYCODE_F18 = 307,
  KEYCODE_F19 = 308,
  KEYCODE_F20 = 309,
  KEYCODE_F21 = 310,
  KEYCODE_F22 = 311,
  KEYCODE_F23 = 312,
  KEYCODE_F24 = 313,
  KEYCODE_F25 = 314,
  KEYCODE_KP_0 = 320,
  KEYCODE_KP_1 = 321,
  KEYCODE_KP_2 = 322,
  KEYCODE_KP_3 = 323,
  KEYCODE_KP_4 = 324,
  KEYCODE_KP_5 = 325,
  KEYCODE_KP_6 = 326,
  KEYCODE_KP_7 = 327,
  KEYCODE_KP_8 = 328,
  KEYCODE_KP_9 = 329,
  KEYCODE_KP_DECIMAL = 330,
  KEYCODE_KP_DIVIDE = 331,
  KEYCODE_KP_MULTIPLY = 332,
  KEYCODE_KP_SUBTRACT = 333,
  KEYCODE_KP_ADD = 334,
  KEYCODE_KP_ENTER = 335,
  KEYCODE_KP_EQUAL = 336,
  KEYCODE_LEFT_SHIFT = 340,
  KEYCODE_LEFT_CONTROL = 341,
  KEYCODE_LEFT_ALT = 342,
  KEYCODE_LEFT_SUPER = 343,
  KEYCODE_RIGHT_SHIFT = 344,
  KEYCODE_RIGHT_CONTROL = 345,
  KEYCODE_RIGHT_ALT = 346,
  KEYCODE_RIGHT_SUPER = 347,
  KEYCODE_MENU = 348,
} KeyCodes;

enum {
  MODIFIER_SHIFT = 0x1, // left or right shift key
  MODIFIER_CTRL = 0x2,  // left or right control key
  MODIFIER_ALT = 0x4,   // left or right alt key
  MODIFIER_SUPER = 0x8, // left or right 'super' key
  MODIFIER_LMB = 0x100, // left mouse button
  MODIFIER_RMB = 0x200, // right mouse button
  MODIFIER_MMB = 0x400, // middle mouse button
};

typedef enum MouseDownState {
  STATE_UP,
  STATE_DOWN,
  STATE_PAN,
  STATE_CLICK,
  STATE_DESELECT,
  STATE_SELECT_AREA,
  STATE_SELECT_ONE,
  STATE_MOVE_SELECTION,
  STATE_CLICK_ENDPOINT,
  STATE_CLICK_PORT,
  STATE_DRAG_WIRING,
  STATE_START_CLICK_WIRING,
  STATE_CLICK_WIRING,
  STATE_CONNECT_PORT,
  STATE_CANCEL_WIRE,
  STATE_FLOATING_WIRE,
  STATE_ADDING_COMPONENT,
  STATE_ADD_COMPONENT,
  STATE_ADDING_WAYPOINT,
  STATE_ADD_WAYPOINT,
} MouseDownState;

typedef enum ToolState {
  TOOL_NONE,
  TOOL_WAYPOINT,
  TOOL_SYMBOL,
  TOOL_WIRE,
} ToolState;

typedef struct Input {
  bv(uint64_t) keysDown;
  bv(uint64_t) keysPressed;
  uint16_t modifiers;
  double frameDuration;
  HMM_Vec2 mousePos;
  HMM_Vec2 mouseDelta;
  HMM_Vec2 scroll;
} Input;

typedef struct UndoCommand {
  enum {
    UNDO_NONE,
    UNDO_MOVE_SELECTION,
    UNDO_SELECT_ITEM,
    UNDO_SELECT_AREA,
    UNDO_DESELECT_ITEM,
    UNDO_DESELECT_AREA,
    UNDO_ADD_SYMBOL,
    UNDO_DEL_SYMBOL,
    UNDO_ADD_WAYPOINT,
    UNDO_DEL_WAYPOINT,
  } verb;

  union {
    struct { // for UNDO_MOVE_SELECTION
      HMM_Vec2 oldCenter;
      HMM_Vec2 newCenter;
      bool snap;
    };
    struct { // for UNDO_SELECT_ITEM, UNDO_DESELECT_ITEM
      ID selectedID;
    };
    struct { // for UNDO_SELECT_AREA, UNDO_DESELECT_AREA
      Box area;
    };
    struct { // for UNDO_ADD_SYMBOL, UNDO_DEL_SYMBOL, UNDO_ADD_WAYPONT,
             // UNDO_DEL_WAYPOINT
      HMM_Vec2 center;
      ID parentID;
      ID childID;
    };
  };
} UndoCommand;

static inline UndoCommand
undo_cmd_move_selection(HMM_Vec2 oldCenter, HMM_Vec2 newCenter, bool snap) {
  return (UndoCommand){
    .verb = UNDO_MOVE_SELECTION,
    .oldCenter = oldCenter,
    .newCenter = newCenter,
    .snap = false,
  };
}

static inline UndoCommand undo_cmd_select_item(ID selectedID) {
  return (UndoCommand){
    .verb = UNDO_SELECT_ITEM,
    .selectedID = selectedID,
  };
}
static inline UndoCommand undo_cmd_deselect_item(ID selectedID) {
  return (UndoCommand){
    .verb = UNDO_DESELECT_ITEM,
    .selectedID = selectedID,
  };
}

static inline UndoCommand undo_cmd_select_area(Box area) {
  return (UndoCommand){
    .verb = UNDO_SELECT_AREA,
    .area = area,
  };
}

static inline UndoCommand undo_cmd_deselect_area(Box area) {
  return (UndoCommand){
    .verb = UNDO_DESELECT_AREA,
    .area = area,
  };
}

static inline UndoCommand
undo_cmd_add_symbol(HMM_Vec2 center, ID symbolID, ID symbolKindID) {
  return (UndoCommand){
    .verb = UNDO_ADD_SYMBOL,
    .center = center,
    .childID = symbolID,
    .parentID = symbolKindID,
  };
}

static inline UndoCommand
undo_cmd_del_symbol(HMM_Vec2 center, ID symbolID, ID symbolKindID) {
  return (UndoCommand){
    .verb = UNDO_DEL_SYMBOL,
    .center = center,
    .childID = symbolID,
    .parentID = symbolKindID,
  };
}

static inline UndoCommand
undo_cmd_add_waypoint(HMM_Vec2 center, ID waypointID, ID endpointID) {
  return (UndoCommand){
    .verb = UNDO_ADD_WAYPOINT,
    .center = center,
    .childID = waypointID,
    .parentID = endpointID,
  };
}

static inline UndoCommand
undo_cmd_del_waypoint(HMM_Vec2 center, ID waypointID, ID endpointID) {
  return (UndoCommand){
    .verb = UNDO_DEL_WAYPOINT,
    .center = center,
    .childID = waypointID,
    .parentID = endpointID,
  };
}

typedef void AvoidRouter;

typedef struct CircuitUX {
  CircuitView view;
  Input input;
  AutoRoute *router;

  bool changed;

  arr(UndoCommand) undoStack;
  arr(UndoCommand) redoStack;

  ToolState tool;

  MouseDownState mouseDownState;

  PortRef clickedPort;

  HMM_Vec2 downStart;
  HMM_Vec2 selectionCenter;

  ID addingSymbol;

  bool newNet;
  ID endpointStart;
  ID endpointEnd;

  arr(BVHLeaf) bvhQuery;

  float zoomExp;

  bool rtDebugLines;
  RoutingConfig routingConfig;
  bool showFPS;

  BVH bvh;
  bool bvhDebugLines;
  int bvhDebugLevel;
} CircuitUX;

void ux_global_init();

void ux_init(
  CircuitUX *ux, const SymbolDesc *componentDescs, DrawContext *drawCtx,
  FontHandle font);
void ux_reset(CircuitUX *ux);
void ux_free(CircuitUX *ux);

HMM_Vec2 ux_calc_snap(CircuitUX *ux, HMM_Vec2 newCenter);
HMM_Vec2 ux_calc_selection_center(CircuitUX *ux);

void ux_update(CircuitUX *ux);
void ux_draw(CircuitUX *ux);
void ux_do(CircuitUX *ux, UndoCommand command);
UndoCommand ux_undo(CircuitUX *ux);
UndoCommand ux_redo(CircuitUX *ux);
void ux_select_none(CircuitUX *ux);
void ux_select_all(CircuitUX *ux);
void ux_delete_selected(CircuitUX *ux);

void ux_start_adding_symbol(CircuitUX *ux, ID symbolKindID);
void ux_stop_adding_symbol(CircuitUX *ux);
void ux_change_adding_symbol(CircuitUX *ux, ID symbolKindID);

void ux_start_wire(CircuitUX *ux, PortRef portRef);
void ux_continue_wire(CircuitUX *ux, ID endpointID);
void ux_cancel_wire(CircuitUX *ux);
void ux_connect_wire(CircuitUX *ux, PortRef portRef);

void ux_start_adding_waypoint(CircuitUX *ux);
void ux_stop_adding_waypoint(CircuitUX *ux);

void ux_add_waypoint(CircuitUX *ux, HMM_Vec2 worldMousePos);

void ux_route(CircuitUX *ux);
void ux_build_bvh(CircuitUX *ux);

#endif // UX_H