#include <stdio.h>
#include <libusb-1.0/libusb.h>

int main()
{
	libusb_context *ctx = NULL;
	libusb_device **devs;
	int cnt;

	//initializer the libusb library
	if(libusb_init(&ctx)<0)
	{
		fprintf(stderr, "failed to Initialize libusb\n");
		return 1;
	}

	// get the list of USB devices

	cnt = libusb_get_device_list(ctx, &devs);
	if(cnt < 0)
	{
		fprintf(stderr,"failed to get device list");
		libusb_exit(ctx);
		return 1;
	}

	printf("Found %d  USB devices\n", cnt);

	// Print information about each connected USB device
	for(int i = 0; i<cnt; i++)
	{
		libusb_device *dev = devs[i];
		struct libusb_device_descriptor desc;

		if(libusb_get_device_descriptor(dev, &desc)< 0)
		{
			fprintf(stderr,"failed to get device descriptor\n");
		}
		else
		{
			printf("Decice %d: VID=0x%04x PID=%04x\n", i, desc.idVendor, desc.idProduct);
		}
	}
	
	// Free list of devices , unreference each devices to allow them to be freed
	libusb_free_device_list(devs,1);

	// Close the libusb context
	libusb_exit(ctx);

	printf("program Finished Successfully\n");
	return 0;
}
