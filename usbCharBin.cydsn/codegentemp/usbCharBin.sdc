# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\MSOE\2014-2015\Winter\CE4950_021_Network\lab\Project\ce4950Project\Networking\usbCharBin.cydsn\usbCharBin.cyprj
# Date: Tue, 20 Jan 2015 00:17:16 GMT
#set_units -time ns
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyILO} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_clock -name {CyBUS_CLK(fixed-function)} -period 41.666666666666664 -waveform {0 20.8333333333333} [get_pins {ClockBlock/clk_bus_glb_ff}]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for D:\MSOE\2014-2015\Winter\CE4950_021_Network\lab\Project\ce4950Project\Networking\usbCharBin.cydsn\TopDesign\TopDesign.cysch
# Project: D:\MSOE\2014-2015\Winter\CE4950_021_Network\lab\Project\ce4950Project\Networking\usbCharBin.cydsn\usbCharBin.cyprj
# Date: Tue, 20 Jan 2015 00:17:11 GMT
