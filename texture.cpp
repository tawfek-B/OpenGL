#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>
#include <GL/gl.h>            // Header File For The OpenGL32 Library
#include <GL/glu.h>            // Header File For The GLu32 Library
#include <GL/glaux.h>        // Header File For The Glaux Library
#include <texture.h>


/**********************************************************
 *
 * VARIABLES DECLARATION
 *
 *********************************************************/

int num_texture = -1; //Counter to keep track of the last loaded texture



/**********************************************************
 *
 * FUNCTION LoadBitmap(char *)
 *
 * This function loads a bitmap file and return the OpenGL reference ID to use that texture
 *
 *********************************************************/
int LoadTexture(const char* filename, int alpha)
{
    int i, j = 0; // Index variables
    FILE* l_file; // File pointer
    unsigned char* l_texture; // Pointer to the memory for the texture

    // Windows.h gives us these types to work with the Bitmap files
    BITMAPFILEHEADER fileheader;
    BITMAPINFOHEADER infoheader;
    RGBTRIPLE rgb;

    num_texture++; // Increment the texture counter

    if ((l_file = fopen(filename, "rb")) == NULL) {
        printf("Error: Unable to open file %s\n", filename); // Error message
        return (-1); // Open the file for reading
    }

    fread(&fileheader, sizeof(fileheader), 1, l_file); // Read the fileheader
    fseek(l_file, sizeof(fileheader), SEEK_SET); // Jump the fileheader
    fread(&infoheader, sizeof(infoheader), 1, l_file); // Read the infoheader

    // Allocate memory for the image (width * height * color depth)
    l_texture = (unsigned char*)malloc(infoheader.biWidth * infoheader.biHeight * 4);
    memset(l_texture, 0, infoheader.biWidth * infoheader.biHeight * 4); // Fill it with zeros

    for (i = 0; i < infoheader.biWidth * infoheader.biHeight; i++)
    {
        fread(&rgb, sizeof(rgb), 1, l_file);
        l_texture[j + 0] = rgb.rgbtRed;
        l_texture[j + 1] = rgb.rgbtGreen;
        l_texture[j + 2] = rgb.rgbtBlue;
        l_texture[j + 3] = alpha; // Alpha value
        j += 4; // Move to the next position
    }

    fclose(l_file); // Close the file stream

    glBindTexture(GL_TEXTURE_2D, num_texture);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    glTexImage2D(GL_TEXTURE_2D, 0, 4, infoheader.biWidth, infoheader.biHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, infoheader.biWidth, infoheader.biHeight, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);

    free(l_texture); // Free the memory used to load the texture

    return (num_texture); // Returns the current OpenGL texture ID
}
