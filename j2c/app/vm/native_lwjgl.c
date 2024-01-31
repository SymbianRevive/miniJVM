#include <stdlib.h>
#include "../../vm/jvm.h"
//native methods

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SDL/SDL.h>

void func_java_awt_Dimension_initIDs___V(JThreadRuntime *runtime){
    return ;
}


JArray * func_java_awt_image_BufferedImage_getRGB__IIII_3III__3I(JThreadRuntime *runtime, struct java_awt_image_BufferedImage* p0, s32 p1, s32 p2, s32 p3, s32 p4, JArray * p5, s32 p6, s32 p7){
    return NULL;
}


JArray * func_javax_imageio_ImageIO_readInternal___3B_3I__3I(JThreadRuntime *runtime, JArray * p0, JArray * p1){
    return NULL;
}


s64 func_org_lwjgl_BufferUtils_getBufferAddress__Ljava_nio_Buffer_2_J(JThreadRuntime *runtime, struct java_nio_Buffer* p0){
    return 0;
}


void func_org_lwjgl_BufferUtils_zeroBuffer0__Ljava_nio_Buffer_2JJ_V(JThreadRuntime *runtime, struct java_nio_Buffer* p0, s64 p1, s64 p3){
    return ;
}


void func_org_lwjgl_input_Keyboard_create___V(JThreadRuntime *runtime){
    return ;
}


void func_org_lwjgl_input_Keyboard_destroy___V(JThreadRuntime *runtime){
    return ;
}


s32 func_org_lwjgl_input_Keyboard_getEventKey___I(JThreadRuntime *runtime){
    return 0;
}


s8 func_org_lwjgl_input_Keyboard_getEventKeyState___Z(JThreadRuntime *runtime){
    return 0;
}


s8 func_org_lwjgl_input_Keyboard_isKeyDown__I_Z(JThreadRuntime *runtime, s32 p0){
    return 0;
}


s8 func_org_lwjgl_input_Keyboard_next___Z(JThreadRuntime *runtime){
    return 0;
}


void func_org_lwjgl_input_Mouse_create___V(JThreadRuntime *runtime){
    return ;
}


void func_org_lwjgl_input_Mouse_destroy___V(JThreadRuntime *runtime){
    return ;
}


s32 func_org_lwjgl_input_Mouse_getDX___I(JThreadRuntime *runtime){
    return 0;
}


s32 func_org_lwjgl_input_Mouse_getDY___I(JThreadRuntime *runtime){
    return 0;
}


s32 func_org_lwjgl_input_Mouse_getEventButton___I(JThreadRuntime *runtime){
    return 0;
}


s8 func_org_lwjgl_input_Mouse_getEventButtonState___Z(JThreadRuntime *runtime){
    return 0;
}


s32 func_org_lwjgl_input_Mouse_getEventDWheel___I(JThreadRuntime *runtime){
    return 0;
}


s32 func_org_lwjgl_input_Mouse_getEventX___I(JThreadRuntime *runtime){
    return 0;
}


s32 func_org_lwjgl_input_Mouse_getEventY___I(JThreadRuntime *runtime){
    return 0;
}


s32 func_org_lwjgl_input_Mouse_getX___I(JThreadRuntime *runtime){
    return 0;
}


s32 func_org_lwjgl_input_Mouse_getY___I(JThreadRuntime *runtime){
    return 0;
}


s8 func_org_lwjgl_input_Mouse_isButtonDown__I_Z(JThreadRuntime *runtime, s32 p0){
    return 0;
}


s8 func_org_lwjgl_input_Mouse_next___Z(JThreadRuntime *runtime){
    return 0;
}


void func_org_lwjgl_input_Mouse_setCursorPosition__II_V(JThreadRuntime *runtime, s32 p0, s32 p1){
    return ;
}


void func_org_lwjgl_input_Mouse_setGrabbed__Z_V(JThreadRuntime *runtime, s8 p0){
    return ;
}

SDL_Surface *screen;
void func_org_lwjgl_opengl_Display_create___V(JThreadRuntime *runtime){
    // int argc = 1;
    // char *argv[1] = {"test"};
    // glutInit(&argc, argv);
    
    // glutCreateWindow("j2c");
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    
    screen = SDL_SetVideoMode(640, 480, 0, SDL_OPENGL);
     
    return ;
}


void func_org_lwjgl_opengl_Display_update___V(JThreadRuntime *runtime){
    // glutSwapBuffers();
    SDL_GL_SwapBuffers();
    return ;
}


void func_org_lwjgl_opengl_GL11_glAlphaFunc__IF_V(JThreadRuntime *runtime, s32 p0, f32 p1){
    glAlphaFunc(p0, p1);
    return ;
}


void func_org_lwjgl_opengl_GL11_glBegin__I_V(JThreadRuntime *runtime, s32 p0){
    glBegin(p0);
    return ;
}


void func_org_lwjgl_opengl_GL11_glBindTexture__II_V(JThreadRuntime *runtime, s32 p0, s32 p1){
    glBindTexture(p0, p1);
    return ;
}


void func_org_lwjgl_opengl_GL11_glBlendFunc__II_V(JThreadRuntime *runtime, s32 p0, s32 p1){
    glBlendFunc(p0, p1);
    return ;
}


void func_org_lwjgl_opengl_GL11_glCallList__I_V(JThreadRuntime *runtime, s32 p0){
    glCallList(p0);
    return ;
}


void func_org_lwjgl_opengl_GL11_glCallLists__Ljava_nio_IntBuffer_2_V(JThreadRuntime *runtime, struct java_nio_IntBuffer* p0){
//     
    return ;
}


void func_org_lwjgl_opengl_GL11_glClear__I_V(JThreadRuntime *runtime, s32 p0){
    glClear(p0);
    return ;
}


void func_org_lwjgl_opengl_GL11_glClearColor__FFFF_V(JThreadRuntime *runtime, f32 p0, f32 p1, f32 p2, f32 p3){
    glClearColor(p0, p1, p2, p3);
    return ;
}


void func_org_lwjgl_opengl_GL11_glClearDepth__D_V(JThreadRuntime *runtime, f64 p0){
    glClearDepth(p0);
    return ;
}


void func_org_lwjgl_opengl_GL11_glColor3f__FFF_V(JThreadRuntime *runtime, f32 p0, f32 p1, f32 p2){
    glColor3f(p0, p1, p2);
    return ;
}


void func_org_lwjgl_opengl_GL11_glColor4f__FFFF_V(JThreadRuntime *runtime, f32 p0, f32 p1, f32 p2, f32 p3){
    glColor4f(p0, p1, p2, p3);
    return ;
}


void func_org_lwjgl_opengl_GL11_glColorMask__ZZZZ_V(JThreadRuntime *runtime, s8 p0, s8 p1, s8 p2, s8 p3){
    glColorMask(p0, p1, p2, p3);
    return ;
}


void func_org_lwjgl_opengl_GL11_glColorMaterial__II_V(JThreadRuntime *runtime, s32 p0, s32 p1){
    glColorMaterial(p0, p1);
    return ;
}


void func_org_lwjgl_opengl_GL11_glColorPointer__IILjava_nio_FloatBuffer_2_V(JThreadRuntime *runtime, s32 p0, s32 p1, struct java_nio_FloatBuffer* p2){
    return ;
}


void func_org_lwjgl_opengl_GL11_glColorPointer__IZILjava_nio_ByteBuffer_2_V(JThreadRuntime *runtime, s32 p0, s8 p1, s32 p2, struct java_nio_ByteBuffer* p3){
    return ;
}


void func_org_lwjgl_opengl_GL11_glCullFace__I_V(JThreadRuntime *runtime, s32 p0){
    glCullFace(p0);
    return ;
}


void func_org_lwjgl_opengl_GL11_glDepthFunc__I_V(JThreadRuntime *runtime, s32 p0){
    glDepthFunc(p0);
    return ;
}


void func_org_lwjgl_opengl_GL11_glDepthMask__Z_V(JThreadRuntime *runtime, s8 p0){
    glDepthMask(p0);
    return ;
}


void func_org_lwjgl_opengl_GL11_glDisable__I_V(JThreadRuntime *runtime, s32 p0){
    glDisable(p0);
    return ;
}


void func_org_lwjgl_opengl_GL11_glDisableClientState__I_V(JThreadRuntime *runtime, s32 p0){
    glDisableClientState(p0);
    return ;
}


void func_org_lwjgl_opengl_GL11_glDrawArrays__III_V(JThreadRuntime *runtime, s32 p0, s32 p1, s32 p2){
    glDrawArrays(p0, p1, p2);
    return ;
}


void func_org_lwjgl_opengl_GL11_glDrawElements__ILjava_nio_IntBuffer_2_V(JThreadRuntime *runtime, s32 p0, struct java_nio_IntBuffer* p1){
    return ;
}


void func_org_lwjgl_opengl_GL11_glEnable__I_V(JThreadRuntime *runtime, s32 p0){
    glEnable(p0);
    return ;
}


void func_org_lwjgl_opengl_GL11_glEnableClientState__I_V(JThreadRuntime *runtime, s32 p0){
    glEnableClientState(p0);
    return ;
}


void func_org_lwjgl_opengl_GL11_glEnd___V(JThreadRuntime *runtime){
    glEnd();
    return ;
}


void func_org_lwjgl_opengl_GL11_glEndList___V(JThreadRuntime *runtime){
    glEndList();
    return ;
}


void func_org_lwjgl_opengl_GL11_glFog__ILjava_nio_FloatBuffer_2_V(JThreadRuntime *runtime, s32 p0, struct java_nio_FloatBuffer* p1){
    return ;
}


void func_org_lwjgl_opengl_GL11_glFogf__IF_V(JThreadRuntime *runtime, s32 p0, f32 p1){
    glFogf(p0, p1);
    return ;
}


void func_org_lwjgl_opengl_GL11_glFogi__II_V(JThreadRuntime *runtime, s32 p0, s32 p1){
    glFogi(p0, p1);
    return ;
}


s32 func_org_lwjgl_opengl_GL11_glGenLists__I_I(JThreadRuntime *runtime, s32 p0){
    return glGenLists(p0);
}


void func_org_lwjgl_opengl_GL11_glGenTextures__Ljava_nio_IntBuffer_2_V(JThreadRuntime *runtime, struct java_nio_IntBuffer* p0){
    return ;
}


s32 func_org_lwjgl_opengl_GL11_glGetError___I(JThreadRuntime *runtime){
    return 0;
}


void func_org_lwjgl_opengl_GL11_glGetFloat__ILjava_nio_FloatBuffer_2_V(JThreadRuntime *runtime, s32 p0, struct java_nio_FloatBuffer* p1){
    return ;
}


void func_org_lwjgl_opengl_GL11_glGetInteger__ILjava_nio_IntBuffer_2_V(JThreadRuntime *runtime, s32 p0, struct java_nio_IntBuffer* p1){
    return ;
}


void func_org_lwjgl_opengl_GL11_glInitNames___V(JThreadRuntime *runtime){
    glInitNames();
    return ;
}


void func_org_lwjgl_opengl_GL11_glInterleavedArrays__IILjava_nio_FloatBuffer_2_V(JThreadRuntime *runtime, s32 p0, s32 p1, struct java_nio_FloatBuffer* p2){
    return ;
}


void func_org_lwjgl_opengl_GL11_glLight__IILjava_nio_FloatBuffer_2_V(JThreadRuntime *runtime, s32 p0, s32 p1, struct java_nio_FloatBuffer* p2){
    return ;
}


void func_org_lwjgl_opengl_GL11_glLightModel__ILjava_nio_FloatBuffer_2_V(JThreadRuntime *runtime, s32 p0, struct java_nio_FloatBuffer* p1){
    return ;
}


void func_org_lwjgl_opengl_GL11_glLightModelf__IF_V(JThreadRuntime *runtime, s32 p0, f32 p1){
    glLightModelf(p0, p1);
    return ;
}


void func_org_lwjgl_opengl_GL11_glLineWidth__F_V(JThreadRuntime *runtime, f32 p0){
    glLineWidth(p0);
    return ;
}


void func_org_lwjgl_opengl_GL11_glLoadIdentity___V(JThreadRuntime *runtime){
    glLoadIdentity();
    return ;
}


void func_org_lwjgl_opengl_GL11_glLoadName__I_V(JThreadRuntime *runtime, s32 p0){
    glLoadName(p0);
    return ;
}


void func_org_lwjgl_opengl_GL11_glMatrixMode__I_V(JThreadRuntime *runtime, s32 p0){
    glMatrixMode(p0);
    return ;
}


void func_org_lwjgl_opengl_GL11_glNewList__II_V(JThreadRuntime *runtime, s32 p0, s32 p1){
    glNewList(p0, p1);
    return ;
}


void func_org_lwjgl_opengl_GL11_glNormal3f__FFF_V(JThreadRuntime *runtime, f32 p0, f32 p1, f32 p2){
    glNormal3f(p0, p1, p2);
    return ;
}


void func_org_lwjgl_opengl_GL11_glNormalPointer__ILjava_nio_ByteBuffer_2_V(JThreadRuntime *runtime, s32 p0, struct java_nio_ByteBuffer* p1){
    return ;
}


void func_org_lwjgl_opengl_GL11_glNormalPointer__ILjava_nio_FloatBuffer_2_V(JThreadRuntime *runtime, s32 p0, struct java_nio_FloatBuffer* p1){
    return ;
}


void func_org_lwjgl_opengl_GL11_glOrtho__DDDDDD_V(JThreadRuntime *runtime, f64 p0, f64 p2, f64 p4, f64 p6, f64 p8, f64 p10){
    glOrtho(p0, p2, p4, p6, p8, p10);
    return ;
}


void func_org_lwjgl_opengl_GL11_glPopMatrix___V(JThreadRuntime *runtime){
    glPopMatrix();
    return ;
}


void func_org_lwjgl_opengl_GL11_glPopName___V(JThreadRuntime *runtime){
    glPopName();
    return ;
}


void func_org_lwjgl_opengl_GL11_glPushMatrix___V(JThreadRuntime *runtime){
    glPushMatrix();
    return ;
}


void func_org_lwjgl_opengl_GL11_glPushName__I_V(JThreadRuntime *runtime, s32 p0){
    glPushName(p0);
    return ;
}


s32 func_org_lwjgl_opengl_GL11_glRenderMode__I_I(JThreadRuntime *runtime, s32 p0){
    glRenderMode(p0);
    return 0;
}


void func_org_lwjgl_opengl_GL11_glRotatef__FFFF_V(JThreadRuntime *runtime, f32 p0, f32 p1, f32 p2, f32 p3){
    glRotatef(p0, p1, p2, p3);
    return ;
}


void func_org_lwjgl_opengl_GL11_glScalef__FFF_V(JThreadRuntime *runtime, f32 p0, f32 p1, f32 p2){
    glScalef(p0, p1, p2);
    return ;
}


void func_org_lwjgl_opengl_GL11_glSelectBuffer__Ljava_nio_IntBuffer_2_V(JThreadRuntime *runtime, struct java_nio_IntBuffer* p0){
    return ;
}


void func_org_lwjgl_opengl_GL11_glShadeModel__I_V(JThreadRuntime *runtime, s32 p0){
    glShadeModel(p0);
    return ;
}


void func_org_lwjgl_opengl_GL11_glTexCoord2f__FF_V(JThreadRuntime *runtime, f32 p0, f32 p1){
    glTexCoord2f(p0, p1);
    return ;
}


void func_org_lwjgl_opengl_GL11_glTexCoordPointer__IILjava_nio_FloatBuffer_2_V(JThreadRuntime *runtime, s32 p0, s32 p1, struct java_nio_FloatBuffer* p2){
    return ;
}


void func_org_lwjgl_opengl_GL11_glTexImage2D__IIIIIIIILjava_nio_ByteBuffer_2_V(JThreadRuntime *runtime, s32 p0, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5, s32 p6, s32 p7, struct java_nio_ByteBuffer* p8){
    return ;
}


void func_org_lwjgl_opengl_GL11_glTexParameteri__III_V(JThreadRuntime *runtime, s32 p0, s32 p1, s32 p2){
    glTexParameteri(p0, p1, p2);
    return ;
}


void func_org_lwjgl_opengl_GL11_glTexSubImage2D__IIIIIIIILjava_nio_ByteBuffer_2_V(JThreadRuntime *runtime, s32 p0, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5, s32 p6, s32 p7, struct java_nio_ByteBuffer* p8){
    return ;
}


void func_org_lwjgl_opengl_GL11_glTranslatef__FFF_V(JThreadRuntime *runtime, f32 p0, f32 p1, f32 p2){
    glTranslatef(p0, p1, p2);
    return ;
}


void func_org_lwjgl_opengl_GL11_glVertex2f__FF_V(JThreadRuntime *runtime, f32 p0, f32 p1){
    glVertex2f(p0, p1);
    return ;
}


void func_org_lwjgl_opengl_GL11_glVertex3f__FFF_V(JThreadRuntime *runtime, f32 p0, f32 p1, f32 p2){
    glVertex3f(p0, p1, p2);
    return ;
}


void func_org_lwjgl_opengl_GL11_glVertexPointer__IILjava_nio_FloatBuffer_2_V(JThreadRuntime *runtime, s32 p0, s32 p1, struct java_nio_FloatBuffer* p2){
    return ;
}


void func_org_lwjgl_opengl_GL11_glViewport__IIII_V(JThreadRuntime *runtime, s32 p0, s32 p1, s32 p2, s32 p3) {
    glViewport(p0, p1, p2, p3);
    return ;
}


s32 func_org_lwjgl_util_glu_GLU_gluBuild2DMipmaps__IIIIIILjava_nio_ByteBuffer_2_I(JThreadRuntime *runtime, s32 p0, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5, struct java_nio_ByteBuffer* p6){
    return 0;
}


struct java_lang_String* func_org_lwjgl_util_glu_GLU_gluErrorString__I_Ljava_lang_String_2(JThreadRuntime *runtime, s32 p0){
    return NULL;
}


void func_org_lwjgl_util_glu_GLU_gluPerspective__FFFF_V(JThreadRuntime *runtime, f32 p0, f32 p1, f32 p2, f32 p3) {
    gluPerspective(p0, p1, p2, p3);
    return ;
}


void func_org_lwjgl_util_glu_GLU_gluPickMatrix__FFFFLjava_nio_IntBuffer_2_V(JThreadRuntime *runtime, f32 p0, f32 p1, f32 p2, f32 p3, struct java_nio_IntBuffer* p4){
    return ;
}
