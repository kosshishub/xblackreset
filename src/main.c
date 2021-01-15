#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <X11/extensions/Xrandr.h>

int 
main( int argc, char **argv )
{
	if(argc != 2)
	{
		printf("Usage: %s <output>\n", argv[0]);
		return 1;
	}

	Display *dpy = XOpenDisplay(NULL);
	if(!dpy)
	{
		printf("XOpenDisplay failed\n");
		return 1;
	}

	int screen = DefaultScreen (dpy);
	Window root = RootWindow(dpy, screen);

	RRCrtc target_crtc = 0;
	char  *target_name = argv[1];

	int major_versionp = 0;
	int minor_versionp = 0;
	XRRQueryVersion( dpy, &major_versionp, &minor_versionp );
	int xrr_version = major_versionp*100 + minor_versionp;
	if(xrr_version < 102)
	{
		printf("XRR version too old?\n"); 
		return 1;
	}

	XRRScreenResources * res = XRRGetScreenResources( dpy, root );
	int n = res->noutput;
	for( int i = 0; i < n; ++i )
	{	
		RROutput output = res->outputs[i];
		XRROutputInfo * output_info = XRRGetOutputInfo( dpy, res, output);
			
		if ( strcmp(output_info->name, target_name) == 0 ){
			target_crtc = output_info->crtc;
			break;
		}
		XRRFreeOutputInfo( output_info ); 
	}

	if(!target_crtc)
	{
		printf("Invalid output\n");
		return 1;
	}

	int ramp_size = XRRGetCrtcGammaSize( dpy, target_crtc );

	XRRCrtcGamma *gamma = NULL;
	gamma = XRRGetCrtcGamma(dpy, target_crtc);
	if(!gamma)
	{
		printf("XRRGetCrtcGamma failed\n");
		return 1;
	}

	int i = 0;
	gamma->red  [i] = 0;
	gamma->green[i] = 0;
	gamma->blue [i] = 0;

	XRRSetCrtcGamma(dpy, target_crtc, gamma);
	XRRFreeGamma (gamma);

	XCloseDisplay (dpy);
}

