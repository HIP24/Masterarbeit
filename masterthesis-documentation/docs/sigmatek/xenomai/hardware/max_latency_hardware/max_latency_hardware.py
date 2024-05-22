import matplotlib.pyplot as plt
import numpy as np

# Data points
x = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,298,299,300,301,302,303,304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319,320,321,322,323,324,325,326,327,328,329,330,331,332,333,334,335,336,337,338,339,340,341,342,343,344,345,346,347,348,349,350,351,352,353,354,355,356,357,358,359,360,361,362,363,364,365,366,367,368,369,370,371,372,373,374,375,376,377,378,379,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,398,399,400,401,402,403,404,405,406,407,408,409,410,411,412,413,414,415,416,417,418,419,420,421,422,423,424,425,426,427,428,429,430,431,432,433,434,435,436,437,438,439,440,441,442,443,444,445,446,447,448,449,450,451,452,453,454,455,456,457,458,459,460,461,462,463,464,465,466,467,468,469,470,471,472,473,474,475,476,477,478,479,480,481,482,483,484,485,486,487,488,489,490,491,492,493,494,495,496,497,498,499,500,501,502,503,504,505,506,507,508,509,510,511,512,513,514,515,516,517,518,519,520,521,522,523,524,525,526,527,528,529,530,531,532,533,534,535,536,537,538,539,540,541,542,543,544,545,546,547,548,549,550,551,552,553,554,555,556,557,558,559,560,561,562,563,564,565,566,567,568,569,570,571,572,573,574,575,576,577,578,579,580,581,582,583,584,585,586,587,588,589,590,591,592,593,594,595,596,597,598,599]

y = [3.436,4.195,3.439,6.839,4.187,4.019,4.185,3.529,7.143,3.678,3.900,3.836,3.685,5.463,3.663,3.791,3.427,3.576,5.162,4.429,4.830,3.638,3.339,5.129,3.595,3.923,3.379,3.321,5.230,3.947,3.747,3.435,3.880,5.233,3.860,3.432,3.787,4.377,5.125,3.361,3.596,3.754,3.493,4.846,4.382,3.857,3.450,3.277,4.800,3.894,3.805,3.402,3.379,4.797,3.620,4.483,3.655,5.295,4.507,3.494,3.616,5.151,3.695,6.818,3.749,3.384,3.805,3.341,5.971,4.782,3.353,3.624,4.119,5.300,3.801,3.509,3.656,3.674,4.397,3.837,3.690,3.659,3.768,4.504,4.241,3.743,3.469,3.693,4.883,4.286,4.175,3.708,3.567,4.404,3.514,4.310,3.564,3.638,5.401,3.393,4.099,3.666,3.450,6.112,3.414,3.352,4.383,3.889,4.515,3.751,3.798,4.915,5.245,7.009,3.955,4.190,4.296,3.957,5.513,3.607,4.393,3.407,4.240,5.863,4.002,3.986,3.762,3.851,5.372,3.749,3.537,3.598,3.706,4.487,3.769,3.666,3.750,3.444,5.525,3.699,3.736,4.076,3.636,5.511,3.855,3.929,4.013,3.790,5.489,4.544,3.753,4.329,4.563,5.398,3.443,3.849,3.701,3.837,5.074,3.302,3.883,3.551,3.564,5.287,3.856,4.263,3.663,3.391,6.798,3.921,5.597,4.138,4.165,5.640,3.843,3.613,3.558,4.066,4.844,4.063,3.661,3.207,3.509,6.175,3.275,3.580,3.479,3.443,4.456,4.454,4.199,3.540,3.659,4.624,3.627,3.644,3.487,3.257,4.223,3.657,3.353,3.472,3.353,4.465,3.265,3.540,3.571,3.508,4.596,5.469,3.872,3.565,3.730,4.377,3.705,3.749,3.722,3.895,9.938,3.888,4.443,3.510,3.599,4.956,3.256,4.503,3.587,3.761,4.628,3.842,3.693,3.924,3.336,5.684,3.524,3.887,3.708,8.080,5.008,4.205,3.754,3.480,3.583,4.588,3.594,4.428,3.729,3.580,8.229,5.365,4.352,3.542,4.507,5.229,3.305,4.049,3.342,3.638,4.641,3.408,3.747,3.807,3.560,5.363,3.608,3.799,3.601,4.215,5.037,4.545,3.646,3.558,3.681,5.018,4.227,3.327,3.535,5.924,6.680,3.704,3.943,3.491,4.473,5.434,3.783,3.509,4.666,3.123,4.544,4.451,3.750,3.717,4.370,4.778,3.667,3.526,4.072,3.656,5.350,3.855,3.749,4.728,3.906,5.871,3.650,3.886,4.084,3.776,5.297,3.361,3.827,3.617,4.072,5.688,3.465,3.625,4.201,3.725,4.398,3.755,3.580,3.438,3.617,5.072,3.770,3.832,3.331,4.207,4.970,3.537,4.209,3.739,6.153,4.468,3.777,3.733,3.740,3.830,5.007,5.228,3.976,3.818,3.772,4.758,3.562,3.949,3.567,3.473,5.158,3.989,3.724,3.751,3.632,5.303,4.155,3.549,3.587,3.190,5.246,3.854,3.930,3.604,3.512,5.015,3.867,3.667,3.650,3.822,5.237,3.590,3.435,3.465,3.637,4.727,3.837,3.675,3.351,3.556,4.869,3.554,3.062,3.152,3.788,5.262,3.598,5.746,3.496,3.712,6.413,3.762,3.694,3.412,4.322,4.247,3.650,3.242,3.440,5.049,4.153,3.494,4.249,3.383,3.679,5.040,3.455,3.701,3.651,3.514,5.336,3.421,3.119,3.705,3.376,4.037,2.911,3.266,3.868,4.195,4.723,4.216,4.448,3.278,3.451,5.340,3.473,3.397,3.169,3.030,5.607,3.183,3.496,3.768,3.195,4.874,2.817,3.416,3.371,5.545,5.458,3.778,3.595,3.514,3.914,5.015,3.852,3.433,3.621,3.887,4.461,3.603,3.528,4.319,3.693,4.433,3.325,3.628,3.368,3.709,4.971,3.608,3.779,3.600,3.716,10.709,3.751,4.886,4.143,4.061,5.487,4.663,3.846,3.362,3.518,4.959,3.336,3.663,3.466,3.240,5.380,3.459,3.854,3.748,3.655,4.564,3.224,4.372,3.693,3.654,6.227,3.446,4.305,3.555,3.510,5.617,3.475,3.044,3.487,3.492,5.353,4.074,3.297,3.169,3.542,5.761,4.130,3.692,4.087,3.615,5.067,3.953,3.713,3.523,3.606,4.402,3.696,3.725,3.362,4.661,3.823,3.708,3.340,3.430,3.660,4.979,3.133,3.690,3.461,4.245,4.986,3.838,3.481,3.402,3.384,4.832,3.064,3.945,3.340,3.529,4.643,3.660,3.855,3.279,3.742,5.785,3.505,3.773,3.558,3.270,5.338,3.237,3.446,3.383,3.573,5.043,3.866,3.505,2.994,3.469,4.853,3.908,3.480,3.094,3.653,4.941,3.567,3.829,3.473,3.436,4.743,3.777,3.726,3.467,3.323,5.720,3.344,3.725,3.427,3.754,4.650,3.630,3.711,3.770,3.190,4.967,3.730,3.867,3.139,3.639,4.948,4.192,4.141,3.538,3.448,5.508,3.385,3.622,3.843,5.557,4.493]

# Calculate statistics
max_y = np.max(y)
min_y = np.min(y)
std_y = np.std(y)
average_y = np.mean(y) 

# Print the statistics
print(f"Max: {max_y}")
print(f"Min: {min_y}")
print(f"Standard Deviation: {round(std_y, 2)}")
print(f"Average: {round(average_y, 2)}") 

# Create the plot
plt.figure(figsize=(10, 6))
plt.plot(x, y,'-', color='blue')

# Set the title and labels
plt.title('Latency of Operating System')
plt.xlabel('Time [s]')
plt.ylabel('Latency [µs]')

# Set the x and y axis limits
plt.xlim([0, 600])
plt.ylim([0, 40])

# Save the plot to a file
plt.savefig("max_latency_hardware.png")
#plt.savefig("../../../../../../img/max_latency_hardware.png")

# Print a success message
print("The plot was successfully saved to max_latency_hardware.png")

# Write the statistics to a file
with open('max_latency_hardware_statistics.txt', 'w') as f:
    f.write(f"Average latency: {round(average_y, 2)}us\n") 
    f.write(f"Max latency: {max_y}us\n")
    f.write(f"Min latency: {min_y}us\n")
    f.write(f"Standard Deviation: {round(std_y, 2)}us\n")

# Print a success message
print("The statistics were successfully written to max_latency_hardware_statistics.txt")



