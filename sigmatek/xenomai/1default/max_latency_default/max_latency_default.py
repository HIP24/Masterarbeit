import matplotlib.pyplot as plt
import numpy as np

# Data points
x = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,298,299,300,301,302,303,304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319,320,321,322,323,324,325,326,327,328,329,330,331,332,333,334,335,336,337,338,339,340,341,342,343,344,345,346,347,348,349,350,351,352,353,354,355,356,357,358,359,360,361,362,363,364,365,366,367,368,369,370,371,372,373,374,375,376,377,378,379,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,398,399,400,401,402,403,404,405,406,407,408,409,410,411,412,413,414,415,416,417,418,419,420,421,422,423,424,425,426,427,428,429,430,431,432,433,434,435,436,437,438,439,440,441,442,443,444,445,446,447,448,449,450,451,452,453,454,455,456,457,458,459,460,461,462,463,464,465,466,467,468,469,470,471,472,473,474,475,476,477,478,479,480,481,482,483,484,485,486,487,488,489,490,491,492,493,494,495,496,497,498,499,500,501,502,503,504,505,506,507,508,509,510,511,512,513,514,515,516,517,518,519,520,521,522,523,524,525,526,527,528,529,530,531,532,533,534,535,536,537,538,539,540,541,542,543,544,545,546,547,548,549,550,551,552,553,554,555,556,557,558,559,560,561,562,563,564,565,566,567,568,569,570,571,572,573,574,575,576,577,578,579,580,581,582,583,584,585,586,587,588,589,590,591,592,593,594,595,596,597,598,599]

y = [46.058,45.247,25.008,230.128,44.259,44.513,91.711,22.744,16.245,185.150,36.711,14.202,130.885,48.036,246.716,169.095,219.466,231.073,24.619,177.433,160.088,97.343,64.062,230.267,78.874,252.809,411.265,22.515,27.148,124.784,586.676,298.173,230.910,24.141,154.979,173.566,33.357,222.388,151.711,38.451,67.466,148.420,404.945,343.690,184.156,156.867,160.473,111.409,209.835,46.755,41.262,215.765,453.147,170.542,172.430,30.891,94.188,241.936,28.899,162.442,210.370,151.916,148.249,116.436,156.545,169.587,207.000,341.089,9.360,19.122,111.249,241.644,16.414,169.308,30.421,154.489,25.697,21.663,19.417,4064.225,16.816,24.010,144.224,201.855,148.832,30.122,156.258,496.579,136.403,19.893,14.042,215.474,211.399,30.932,21.589,182.871,168.529,26.291,23.513,21.540,26.199,15.698,12.213,1213.987,78.669,183.154,242.775,175.638,69.769,102.394,83.967,99.656,24.573,218.177,108.713,127.000,13.701,231.670,190.132,235.042,96.299,173.375,175.528,133.886,21.396,129.259,12.632,131.769,27.551,175.399,208.523,154.972,221.602,180.908,223.067,111.292,142.352,19.898,74.817,161.187,311.376,17.038,27.474,110.750,167.509,12.404,90.536,161.824,136.528,27.410,15.690,58.505,256.667,244.765,140.802,205.465,74.799,26.125,215.514,26.843,19.168,15.723,111.505,185.790,239.944,47.677,418.785,15.690,177.398,213.361,162.398,43.181,108.263,128.250,23.710,189.526,182.737,163.860,217.369,97.451,236.625,147.896,138.374,228.625,132.462,176.077,130.587,190.408,1017.088,160.770,67.554,27.102,129.908,206.303,270.965,109.238,139.922,34.335,30.190,24.355,23.302,27.776,24.547,188.686,173.485,156.228,16.056,128.566,14.259,265.675,269.690,203.610,181.352,25.724,29.783,15.547,150.926,173.356,13.783,178.982,42.498,177.951,132.049,177.935,24.525,32.250,124.116,147.811,99.098,23.038,40.415,145.970,220.256,251.117,148.607,33.246,27.089,71.276,123.321,26.517,73.006,194.473,167.213,249.329,570.648,190.634,68.425,180.909,169.027,21.083,13.540,152.768,88.968,14.848,6.963,23.632,232.795,174.460,179.210,210.269,26.256,142.122,209.076,17.153,16.916,19.901,24.666,139.287,2746.094,132.688,31.390,140.984,134.557,23.748,23.969,18.943,27.021,162.324,276.631,129.021,87.483,27.721,392.561,108.004,140.647,83.870,152.610,144.575,192.138,152.445,221.906,92.230,139.172,164.936,145.246,196.138,152.819,153.158,12.769,22.080,92.492,197.199,209.789,168.356,163.938,27.332,188.547,168.949,183.052,154.116,26.958,121.369,211.897,221.899,36.295,32.402,166.892,59.867,27.105,14.650,110.097,172.118,29.988,27.658,220.311,183.575,152.368,211.698,134.616,51.270,108.671,13.548,219.511,109.252,64.613,140.805,149.700,167.807,25.758,30.765,273.123,164.909,165.589,14.878,112.409,179.138,128.386,341.071,80.479,120.418,151.436,167.232,117.961,151.837,343.459,576.624,83.026,14.864,291.525,202.061,214.078,226.545,167.546,226.433,171.912,19.201,146.997,164.363,13.099,124.107,214.734,322.862,173.702,170.163,311.086,91.813,176.570,325.418,180.390,26.203,210.092,87.712,206.417,172.590,155.587,24.720,211.070,24.456,141.462,25.085,133.946,4070.018,23.791,196.018,246.103,23.463,159.743,105.678,43.826,228.944,127.796,177.334,188.556,198.069,363.375,286.065,213.258,142.917,81.932,387.950,165.773,148.521,110.014,254.838,25.412,19.918,257.054,218.566,45.948,29.893,21.854,240.444,18.189,175.604,85.316,140.207,133.251,172.613,171.017,220.708,3939.951,220.420,22.360,140.186,20.653,96.784,164.221,435.337,17.824,157.655,183.606,106.997,79.923,98.318,163.483,91.552,180.445,179.750,127.103,23.167,37.710,354.087,2569.037,26.980,22.115,24.996,197.054,216.713,106.452,53.856,696.160,139.231,209.923,191.278,203.296,168.068,150.064,173.022,76.982,82.013,24.446,544.953,381.607,106.719,247.009,16.932,158.153,175.496,16.598,155.504,137.559,250.553,18.037,17.485,15.028,189.511,222.884,105.779,176.428,25.272,62.036,27.618,1364.292,58.514,96.686,12.729,238.651,218.703,23.869,25.420,167.466,134.191,24.254,23.277,242.985,135.149,20.173,33.589,228.909,18.160,79.284,21.651,28.330,24.800,84.395,210.849,133.704,31.291,74.501,195.666,215.479,972.253,98.867,171.062,165.230,204.254,21.464,146.101,27.601,16.827,17.296,204.706,202.022,212.635,242.466,107.899,24.687,383.024,43.742,16.731,348.275,373.132,112.767,239.302,1540.068,23.941,136.041,140.292,72.251,13.551,74.170,203.932,170.396,178.037,269.349,260.202,243.980,24.721,177.769,124.189,17.647,21.445,24.968,2961.302,28.545,18.846,71.297,22.175,24.419,157.237,185.063,96.272,154.349,65.727,112.406,288.028,27.610,34.325,317.262,248.806,111.234,20.925,103.927,136.724,212.379,18.648,186.993,19.668,21.342,22.662,110.076,241.796,170.161,233.329,263.563,26.732,87.702,170.590,26.381]

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
#plt.title('Latency of Operating System')
plt.xlabel('Time [s]')
plt.ylabel('Latency [µs]')

# Set the x and y axis limits
plt.xlim([0, 600])
plt.ylim([0, 5000])

# Save the plot to a file
plt.savefig("max_latency_default.png")
#plt.savefig("../../../../../../img/max_latency_default.png")

# Print a success message
print("The plot was successfully saved to max_latency_default.png")

# Write the statistics to a file
with open('max_latency_default_statistics.txt', 'w') as f:
    f.write(f"Average latency: {round(average_y, 2)}us\n") 
    f.write(f"Max latency: {round(max_y, 2)}us\n")
    f.write(f"Min latency: {round(min_y, 2)}us\n")
    f.write(f"Standard Deviation: {round(std_y, 2)}us\n")

# Print a success message
print("The statistics were successfully written to max_latency_default_statistics.txt")



