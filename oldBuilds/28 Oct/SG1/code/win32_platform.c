#include <windows.h>                                         
#include <stdint.h>
#include "utils.c"
#include "math.c"

typedef int8_t s8;                                           // 
typedef uint8_t u8;                                          // 
typedef int16_t s16;                                         // 
typedef uint16_t u16;                                        // these set up shift registers for the various
typedef int32_t s32;                                         // graphics resolutions
typedef uint32_t u32;                                        // 
typedef int64_t s64;                                         // 
typedef uint64_t u64;                                        // 
typedef int b32;                                             // declares b32 as integer for future use
                                                             // 
#define true 1                                               // because old programs need this
#define false 0                                              // 
#define global_variable static                               // 
#define internal static                                      // 
#include "software_rendering.c"                              
                                                             // 
global_variable b32 running = true;                          // sort of makes it a default MO
                                                             //
struct {                                                     // this sets up a structure for the buffer to start settin shit up in                                                         
    int width, height;                                       // not platform specifid
    u32 *pixels;                                             // these are all needed later for the callbacks to render. this is like the 
    //Win32_Render_Buffer     non platform specific section   
    BITMAPINFO bitmapinfo;                                   // template. the parent. this structure gets utilized by the render buffer. this line is platform specific
} typedef Render_Buffer;                               // this is the name of the engine I guess                                                                                                                          
 //typedef gameranderbuffer platform specific
                                                             //
global_variable Render_Buffer render_buffer;                 // created as a global variable
                                                                                                                          //                                                             // 
internal LRESULT                                             // making something a 'local' var
window_callback (HWND window, UINT message, WPARAM wParam, LPARAM lParam) // HERE1
{
//    HWND window, UINT message,                               
//    WPARAM wParam, LPARAM lParam){                           
// This creates a procedure for windows torelay info to the game
// basically a pointer for the upcomgin game window to recieve information                                                                                                //
LRESULT result = 0;                                          // initialize the something
                                                             // 
  switch(message){                                           //
    case WM_CLOSE:                                           // Provides kill code
    case WM_DESTROY: {                                       //
        running = false;                                     //
        }break;                                              // end of kill block
    case WM_SIZE: {                                          //
        RECT rect;                                           // get width and height, create the prebuilt gui rect object
        GetWindowRect(window, &rect);                        // another msdn def
        render_buffer.width = rect.right - rect.left;
        render_buffer.height = rect.bottom - rect.top;       
                                                             //
        if (render_buffer.pixels) {                          //
                VirtualFree(render_buffer.pixels,            //
                0, MEM_RELEASE);                             // free up them titties
        }                                                    // allocate memory to render buffer
        render_buffer.pixels = VirualAlloc(0, 
            sizeof(u32)*render_buffer.width*render_buffer.height,  // 3d :D          this is where the magic happens                                          
            MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);               //       
                                                             //       
                                                             // fill the bitmapinfo
        render_buffer.bitmapinfo.bmiHeader.biSize = sizeof(render_buffer.bitmapinfo.bmiHeader);
        render_buffer.bitmapinfo.bmiHeader.biWidth = render_buffer.width;
        render_buffer.bitmapinfo.bmiHeader.biHeight = render_buffer.height;
        render_buffer.bitmapinfo.bmiHeader.biPlanes = 1;
        render_buffer.bitmapinfo.bmiHeader.biBitCount = 32;
        render_buffer.bitmapinfo.bmiHeader.biCompression = BI_RGB;
    }break;                                                  //                                       
                                                             //
    default: {                                               // default for case
  result = DefWindowProcA(window, message, wParam, lParam); }//
                                                             //
return result;                                               //
                                                             //                
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);
{                                                            //
                                                             //                
WNDCLASSA window_class = {0};                                //                                             
  window_class.style = CS_HREDRAW|CS_VREDRAW;                // sets us up for software rendering                                                                             
  window_class.lpfnWndProc = window_callback;                // see where it's linked up with the procedure on top?
  window_class.lpszClassName = "Game_Window_Class";          //                                                                 
                                                             //                
RegisterClassA(&window_class);                               // creating the class for the window to become
                                                             // gave it a pointer to the 'template'                                            
                                                             //
HWND window = CreateWindowExA(0, window_class.lpszClassName, // creating a window, specifying it's class,                                                                              
"Some Game1",WS_VISIBLE|WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,   // name, how it looks, x starting position,
CW_USEDEFAULT,1280,720, 0, 0, 0, 0);                         // y starting position, x width, y height, no parent, no menu, no instance, no lpvoid 
                                                             //
HDC hdc = GetDC(window);                                     // THAT. only called once. only need one window.
                                                             //
                                                             //
                                                             //
While (running);                                             // starts the game loop
  {                                                          //
  MSG message;                                               // INPUT
  while (PeekMessageA(&message, window, 0, 0, PM_REMOVE)) {  // so all these messages are being processed through HERE1
       switch(message.message) {
        case WM_KEYDOWN:  
        case WM_KEYUP:   
             } break;  
                                                             //  
                                                             //
        default: {                                             //
    TranslateMessage(&message);                              // 
    DispatchMessage(&message);                               // 
    }
    }                                                        //  
  }                                                          // 
    // SIMULATION 
  clear_screen(0x551F00);                                                  //int width, height;
  draw_rect_in_pixels(50, 50, 200, 200, 0xff11af);                                                  //void *Memory;
                                                    //BITMAPINFO bitmap_info;
                                                             //
                                                             //
                                                             // RENDER
StretchDIBits(hdc, 0, 0, render_buffer.width,
 render_buffer.height, 0, 0, render_buffer.width,            // all of these were renamed to take the global variable as a framework 
 render_buffer.height, render_buffer.pixels, 
 &render_buffer.bitmapinfo, DIB_RGB_COLORS, SRCCOPY);       // this bitmap gets set as a pointer so the simulation line catches with the other symbol. key - value
}                                                            // all definitions derived from msdn. this tells the system what to draw, gui
}                                                            //
                                                             //
                                                             //
                                                             //
                                                             // 
                                                             //
                                                             //
                                                             //
                                                             //
                                                             //
                                                             //
                                                             //                                                                               
                                                             //
/* typedef struct tagBITMAPINFO {
  BITMAPINFOHEADER bmiHeader;
  RGBQUAD          bmiColors[1];
} BITMAPINFO, *LPBITMAPINFO, *PBITMAPINFO; */