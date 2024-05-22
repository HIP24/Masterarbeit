import matplotlib.pyplot as plt
import numpy as np

# Data points
x = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,298,299,300,301,302,303,304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319,320,321,322,323,324,325,326,327,328,329,330,331,332,333,334,335,336,337,338,339,340,341,342,343,344,345,346,347,348,349,350,351,352,353,354,355,356,357,358,359,360,361,362,363,364,365,366,367,368,369,370,371,372,373,374,375,376,377,378,379,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,398,399,400,401,402,403,404,405,406,407,408,409,410,411,412,413,414,415,416,417,418,419,420,421,422,423,424,425,426,427,428,429,430,431,432,433,434,435,436,437,438,439,440,441,442,443,444,445,446,447,448,449,450,451,452,453,454,455,456,457,458,459,460,461,462,463,464,465,466,467,468,469,470,471,472,473,474,475,476,477,478,479,480,481,482,483,484,485,486,487,488,489,490,491,492,493,494,495,496,497,498,499,500,501,502,503,504,505,506,507,508,509,510,511,512,513,514,515,516,517,518,519,520,521,522,523,524,525,526,527,528,529,530,531,532,533,534,535,536,537,538,539,540,541,542,543,544,545,546,547,548,549,550,551,552,553,554,555,556,557,558,559,560,561,562,563,564,565,566,567,568,569,570,571,572,573,574,575,576,577,578,579,580,581,582,583,584,585,586,587,588,589,590,591,592,593,594,595,596,597,598,599]

y = [62.942,74.276,75.975,90.342,46.809,97.125,63.376,71.999,57.090,68.047,138.986,43.312,78.594,36.142,70.235,36.112,77.012,74.237,80.386,97.918,58.768,60.101,61.785,19.745,80.105,72.658,35.530,39.531,37.041,59.871,96.801,56.187,81.195,27.019,49.315,44.042,56.813,79.088,63.556,46.272,65.568,91.485,73.137,80.338,75.887,72.556,31.676,83.351,88.568,63.402,92.590,30.480,71.572,52.249,64.162,68.496,65.325,58.504,66.847,43.411,61.832,28.243,70.355,46.282,69.171,80.252,107.356,71.816,55.046,115.873,105.572,94.466,52.278,47.561,107.645,65.304,69.019,22.943,65.587,83.922,107.884,139.085,116.211,96.753,43.914,96.986,92.931,79.712,73.857,65.789,73.394,80.850,84.033,107.515,110.322,72.584,108.086,74.402,41.230,103.597,94.054,73.015,55.157,92.607,124.045,117.810,72.953,112.867,107.655,69.600,36.640,65.168,69.796,121.884,79.027,120.508,75.124,116.281,86.184,82.612,107.228,60.312,44.773,103.022,71.492,83.980,65.803,80.783,108.076,79.293,54.549,65.363,69.927,78.100,103.951,70.796,40.048,51.541,67.298,69.931,92.041,59.554,90.923,81.292,115.366,56.683,95.664,42.632,93.935,39.268,79.564,75.566,77.625,61.264,83.628,53.376,84.418,50.551,53.579,78.891,107.525,77.042,36.965,59.496,88.233,93.407,82.967,44.784,81.999,37.722,69.117,74.339,95.120,84.724,54.360,41.230,78.454,95.814,50.589,65.333,54.568,71.401,102.382,73.882,57.023,112.567,53.964,85.228,77.551,102.205,113.502,62.447,49.835,32.601,112.196,55.992,66.112,34.572,73.709,103.299,63.219,69.966,90.632,83.672,48.105,44.489,113.299,67.891,37.389,50.117,28.656,71.951,72.831,66.750,72.465,112.564,73.132,44.150,73.339,52.574,113.058,66.888,83.834,73.343,56.018,51.786,59.459,66.766,50.157,49.137,71.488,118.901,50.922,74.656,42.687,44.727,48.961,64.507,83.082,78.758,133.091,91.012,104.816,93.079,90.066,64.115,75.462,106.746,75.862,55.909,125.732,78.228,89.221,110.222,34.947,51.598,34.423,53.090,32.739,61.965,38.992,27.869,88.243,60.940,62.583,56.414,63.943,87.388,85.457,78.799,60.798,71.344,127.534,49.512,41.394,60.882,88.947,73.649,72.696,70.232,68.270,69.155,109.467,49.442,78.265,109.854,77.532,81.208,108.002,82.056,105.026,40.568,87.974,119.987,107.726,70.664,55.680,89.370,120.914,107.998,59.182,75.602,68.980,93.803,67.133,96.815,64.566,106.514,122.601,54.321,70.367,38.206,115.066,119.502,58.335,86.427,77.217,97.443,35.021,87.624,144.279,66.337,128.497,106.757,68.459,72.702,68.320,106.878,67.147,75.685,71.395,67.530,110.855,76.260,40.756,86.247,42.504,116.979,84.071,108.231,131.669,137.535,125.534,120.662,72.849,64.361,61.881,51.795,110.368,78.513,79.085,69.640,27.554,86.064,49.936,83.218,83.529,49.001,122.786,78.426,89.385,110.746,77.675,71.079,68.631,116.577,116.836,38.566,37.941,80.056,122.207,97.476,62.260,109.469,30.967,67.326,49.161,126.178,107.526,94.398,77.348,51.531,66.454,75.452,92.793,72.642,56.109,50.475,61.755,89.404,86.205,76.689,80.881,23.367,25.409,72.118,81.148,48.194,60.470,90.750,72.400,68.365,108.737,97.448,96.642,21.597,36.244,127.259,52.785,67.909,52.962,43.586,72.293,86.200,47.856,67.092,74.570,86.809,92.632,113.773,14.113,104.443,60.368,64.620,48.559,106.648,60.477,81.091,64.328,58.408,56.288,71.590,42.021,110.858,52.670,73.617,88.698,69.742,68.626,80.696,76.229,31.625,66.070,66.826,61.946,31.406,78.915,66.766,51.015,43.751,57.179,48.322,91.386,106.618,34.268,103.711,107.222,57.605,65.857,56.525,42.657,123.268,53.832,68.979,136.126,78.728,91.287,67.807,134.131,47.609,48.022,48.768,57.981,85.707,55.220,45.734,103.454,46.288,58.076,49.953,84.225,29.681,18.574,40.238,103.693,79.001,92.354,57.814,107.111,73.250,63.864,457.545,110.422,98.523,52.179,89.806,44.743,90.029,37.661,30.156,85.182,166.223,57.706,104.344,39.167,49.276,46.343,58.438,67.866,106.923,43.884,59.617,106.285,70.462,123.701,119.541,72.979,82.920,43.991,93.965,40.478,83.905,57.914,67.751,83.199,85.347,92.876,82.210,50.786,69.795,76.092,71.850,88.652,41.314,78.764,54.940,91.558,78.710,59.173,90.462,75.604,75.900,73.295,83.576,116.833,32.506,74.130,108.902,83.557,80.981,65.893,84.083,80.148,88.848,61.080,91.944,61.030,95.015,71.116,65.975,84.773,93.957,106.928,59.076,52.081,63.749,36.807,24.182,54.097,72.997,76.399,47.241,62.631,74.643,50.340,30.887,93.059,105.172,29.913,69.146,84.525,35.011,59.502,76.837,96.620,91.794,82.425,80.435,61.099,93.228,75.653,81.362,87.391,49.934,55.627,84.398,87.006,80.194,73.888]

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
plt.ylim([0, 500])

# Save the plot to a file
plt.savefig("max_latency_taskset.png")
#plt.savefig("../../../../../../img/max_latency_taskset.png")

# Print a success message
print("The plot was successfully saved to max_latency_taskset.png")

# Write the statistics to a file
with open('max_latency_taskset_statistics.txt', 'w') as f:
    f.write(f"Average latency: {round(average_y, 2)}us\n") 
    f.write(f"Max latency: {max_y}us\n")
    f.write(f"Min latency: {min_y}us\n")
    f.write(f"Standard Deviation: {round(std_y, 2)}us\n")


# Print a success message
print("The statistics were successfully written to max_latency_taskset_statistics.txt")



