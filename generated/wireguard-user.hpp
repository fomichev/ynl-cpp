/* SPDX-License-Identifier: ((GPL-2.0 WITH Linux-syscall-note) OR BSD-3-Clause) */
/* Do not edit directly, auto-generated from: */
/*	 */
/* YNL-GEN user header */

#ifndef _LINUX_WIREGUARD_GEN_H
#define _LINUX_WIREGUARD_GEN_H

#include <linux/types.h>
#include <stdlib.h>
#include <string.h>

#include <list>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <vector>
#include <array>

#include "ynl.hpp"

#include <linux/time_types.h>
#include <linux/wireguard.h>

namespace ynl_cpp {
const struct ynl_family& get_ynl_wireguard_family();

/* Enums */
std::string_view wireguard_op_str(int op);
std::string_view wireguard_wgdevice_flags_str(wgdevice_flag value);
std::string_view wireguard_wgpeer_flags_str(wgpeer_flag value);
std::string_view wireguard_wgallowedip_flags_str(wgallowedip_flag value);

/* Common nested types */
struct wireguard_wgallowedip {
	std::optional<__u32> idx;
	std::optional<__u16> family;
	std::vector<__u8> ipaddr;
	std::optional<__u8> cidr_mask;
	std::optional<__u32> flags;
};

struct wireguard_wgpeer {
	std::optional<__u32> idx;
	std::vector<__u8> public_key;
	std::vector<__u8> preshared_key;
	std::optional<__u32> flags;
	std::vector<__u8> endpoint;
	std::optional<__u16> persistent_keepalive_interval;
	std::optional<struct __kernel_timespec> last_handshake_time;
	std::optional<__u64> rx_bytes;
	std::optional<__u64> tx_bytes;
	std::vector<wireguard_wgallowedip> allowedips;
	std::optional<__u32> protocol_version;
};

/* ============== WG_CMD_GET_DEVICE ============== */
/* WG_CMD_GET_DEVICE - dump */
struct wireguard_get_device_req {
	std::optional<__u32> ifindex;
	std::string ifname;
};

struct wireguard_get_device_rsp {
	std::optional<__u32> ifindex;
	std::string ifname;
	std::vector<__u8> private_key;
	std::vector<__u8> public_key;
	std::optional<__u32> flags;
	std::optional<__u16> listen_port;
	std::optional<__u32> fwmark;
	std::vector<wireguard_wgpeer> peers;
};

struct wireguard_get_device_list {
	std::list<wireguard_get_device_rsp> objs;
};

std::unique_ptr<wireguard_get_device_list>
wireguard_get_device_dump(ynl_cpp::ynl_socket& ys,
			  wireguard_get_device_req& req);

/* ============== WG_CMD_SET_DEVICE ============== */
/* WG_CMD_SET_DEVICE - do */
struct wireguard_set_device_req {
	std::optional<__u32> ifindex;
	std::string ifname;
	std::vector<__u8> private_key;
	std::vector<__u8> public_key;
	std::optional<__u32> flags;
	std::optional<__u16> listen_port;
	std::optional<__u32> fwmark;
	std::vector<wireguard_wgpeer> peers;
};

/*
 * Set WireGuard device
~~~~~~~~~~~~~~~~~~~~

This command should be called with a wgdevice set, containing one but
not both of ``WGDEVICE_A_IFINDEX`` and ``WGDEVICE_A_IFNAME``.

It is possible that the amount of configuration data exceeds that of the
maximum message length accepted by the kernel. In that case, several
messages should be sent one after another, with each successive one
filling in information not contained in the prior. Note that if
``WGDEVICE_F_REPLACE_PEERS`` is specified in the first message, it
probably should not be specified in fragments that come after, so that
the list of peers is only cleared the first time but appended after.
Likewise for peers, if ``WGPEER_F_REPLACE_ALLOWEDIPS`` is specified in
the first message of a peer, it likely should not be specified in
subsequent fragments.

If an error occurs, ``NLMSG_ERROR`` will reply containing an errno.

 */
int wireguard_set_device(ynl_cpp::ynl_socket& ys,
			 wireguard_set_device_req& req);

} //namespace ynl_cpp
#endif /* _LINUX_WIREGUARD_GEN_H */
