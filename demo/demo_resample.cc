#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include "../inc/resampler.h"
#include "../inc/push_resampler.h"

using namespace std;


int main(int argc, char *argv[])
{
    FILE *input = fopen(argv[1], "rb");
    FILE *outfile = fopen(argv[2], "wb");
    const int srcSampleHz = atoi(argv[3]);
    const int dstSampleHz = atoi(argv[4]);
    webrtc::Resampler resampler_;
    webrtc::PushResampler<float> resampler1_;
    resampler1_.InitializeIfNeeded(srcSampleHz, dstSampleHz,1);
    resampler_.ResetIfNeeded(srcSampleHz, dstSampleHz, 1);



    int sample_rate;
    int ch;
    int ret;
    sample_rate = 16000;
    ch = 1;
    const int kSamples = srcSampleHz / 100 * ch;
    const int outkSamples = dstSampleHz /100 * ch;
    short input_samples[kSamples];
    short output_samples[outkSamples];
    float f_output_samples[outkSamples];
    float floatS16input_sample[kSamples];

    int16_t f_output_samples_resampler[outkSamples];
    int16_t intS16input_sample_resampler[kSamples];
    size_t length = kSamples;

    while(!feof(input))
    {
        int read = fread(input_samples, sizeof(short), kSamples, input);
        if (read == kSamples)
        {
            for (int i =0;i<kSamples;i++)
            {
                floatS16input_sample[i] = input_samples[i] / 32768.;
                intS16input_sample_resampler[i] = (int16_t)input_samples[i];
            }

            // resampler1_.Resample(floatS16input_sample, kSamples, f_output_samples, outkSamples); // for PushResampler
            resampler_.Push(intS16input_sample_resampler,kSamples,f_output_samples_resampler,outkSamples,length);
            
            for (int i =0;i<outkSamples;i++)
            {
                // output_samples[i] = (short)(f_output_samples[i] * 32768); // for PushResampler
                output_samples[i] = (short)f_output_samples_resampler[i] ;
            }
        }
        fwrite(output_samples, sizeof(short), outkSamples, outfile);
    }

    fclose(input);
    fclose(outfile);
    std::cout << "wcud" <<std::endl;
    return 0;
}