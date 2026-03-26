// SPDX-License-Identifier: ((GPL-2.0 WITH Linux-syscall-note) OR BSD-3-Clause)
/* Do not edit directly, auto-generated from: */
/*	 */
/* YNL-GEN user source */

#include "wireguard-user.hpp"

#include <array>

#include <linux/time_types.h>
#include <linux/wireguard.h>

#include <linux/genetlink.h>

namespace ynl_cpp {

/* Enums */
static constexpr std::array<std::string_view, WG_CMD_SET_DEVICE + 1> wireguard_op_strmap = []() {
	std::array<std::string_view, WG_CMD_SET_DEVICE + 1> arr{};
	arr[WG_CMD_SET_DEVICE] = "set-device";
	return arr;
} ();

std::string_view wireguard_op_str(int op)
{
	if (op < 0 || op >= (int)(wireguard_op_strmap.size())) {
		return "";
	}
	return wireguard_op_strmap[op];
}

static constexpr std::array<std::string_view, 0 + 1> wireguard_wgdevice_flags_strmap = []() {
	std::array<std::string_view, 0 + 1> arr{};
	arr[0] = "replace-peers";
	return arr;
} ();

std::string_view wireguard_wgdevice_flags_str(wgdevice_flag value)
{
	value = (wgdevice_flag)(ffs(value) - 1);
	if (value < 0 || value >= (int)(wireguard_wgdevice_flags_strmap.size())) {
		return "";
	}
	return wireguard_wgdevice_flags_strmap[value];
}

static constexpr std::array<std::string_view, 2 + 1> wireguard_wgpeer_flags_strmap = []() {
	std::array<std::string_view, 2 + 1> arr{};
	arr[0] = "remove-me";
	arr[1] = "replace-allowedips";
	arr[2] = "update-only";
	return arr;
} ();

std::string_view wireguard_wgpeer_flags_str(wgpeer_flag value)
{
	value = (wgpeer_flag)(ffs(value) - 1);
	if (value < 0 || value >= (int)(wireguard_wgpeer_flags_strmap.size())) {
		return "";
	}
	return wireguard_wgpeer_flags_strmap[value];
}

static constexpr std::array<std::string_view, 0 + 1> wireguard_wgallowedip_flags_strmap = []() {
	std::array<std::string_view, 0 + 1> arr{};
	arr[0] = "remove-me";
	return arr;
} ();

std::string_view wireguard_wgallowedip_flags_str(wgallowedip_flag value)
{
	value = (wgallowedip_flag)(ffs(value) - 1);
	if (value < 0 || value >= (int)(wireguard_wgallowedip_flags_strmap.size())) {
		return "";
	}
	return wireguard_wgallowedip_flags_strmap[value];
}

/* Policies */
static std::array<ynl_policy_attr,WGALLOWEDIP_A_MAX + 1> wireguard_wgallowedip_policy = []() {
	std::array<ynl_policy_attr,WGALLOWEDIP_A_MAX + 1> arr{};
	arr[WGALLOWEDIP_A_UNSPEC].name = "unspec";
	arr[WGALLOWEDIP_A_UNSPEC].type = YNL_PT_REJECT;
	arr[WGALLOWEDIP_A_FAMILY].name = "family";
	arr[WGALLOWEDIP_A_FAMILY].type = YNL_PT_U16;
	arr[WGALLOWEDIP_A_IPADDR].name = "ipaddr";
	arr[WGALLOWEDIP_A_IPADDR].type = YNL_PT_BINARY;
	arr[WGALLOWEDIP_A_CIDR_MASK].name = "cidr-mask";
	arr[WGALLOWEDIP_A_CIDR_MASK].type = YNL_PT_U8;
	arr[WGALLOWEDIP_A_FLAGS].name = "flags";
	arr[WGALLOWEDIP_A_FLAGS].type = YNL_PT_U32;
	return arr;
} ();

struct ynl_policy_nest wireguard_wgallowedip_nest = {
	.max_attr = static_cast<unsigned int>(WGALLOWEDIP_A_MAX),
	.table = wireguard_wgallowedip_policy.data(),
};

static std::array<ynl_policy_attr,WGPEER_A_MAX + 1> wireguard_wgpeer_policy = []() {
	std::array<ynl_policy_attr,WGPEER_A_MAX + 1> arr{};
	arr[WGPEER_A_UNSPEC].name = "unspec";
	arr[WGPEER_A_UNSPEC].type = YNL_PT_REJECT;
	arr[WGPEER_A_PUBLIC_KEY].name = "public-key";
	arr[WGPEER_A_PUBLIC_KEY].type = YNL_PT_BINARY;
	arr[WGPEER_A_PRESHARED_KEY].name = "preshared-key";
	arr[WGPEER_A_PRESHARED_KEY].type = YNL_PT_BINARY;
	arr[WGPEER_A_FLAGS].name = "flags";
	arr[WGPEER_A_FLAGS].type = YNL_PT_U32;
	arr[WGPEER_A_ENDPOINT].name = "endpoint";
	arr[WGPEER_A_ENDPOINT].type = YNL_PT_BINARY;
	arr[WGPEER_A_PERSISTENT_KEEPALIVE_INTERVAL].name = "persistent-keepalive-interval";
	arr[WGPEER_A_PERSISTENT_KEEPALIVE_INTERVAL].type = YNL_PT_U16;
	arr[WGPEER_A_LAST_HANDSHAKE_TIME].name = "last-handshake-time";
	arr[WGPEER_A_LAST_HANDSHAKE_TIME].type = YNL_PT_BINARY;
	arr[WGPEER_A_RX_BYTES].name = "rx-bytes";
	arr[WGPEER_A_RX_BYTES].type = YNL_PT_U64;
	arr[WGPEER_A_TX_BYTES].name = "tx-bytes";
	arr[WGPEER_A_TX_BYTES].type = YNL_PT_U64;
	arr[WGPEER_A_ALLOWEDIPS].name = "allowedips";
	arr[WGPEER_A_ALLOWEDIPS].type = YNL_PT_NEST;
	arr[WGPEER_A_ALLOWEDIPS].nest = &wireguard_wgallowedip_nest;
	arr[WGPEER_A_PROTOCOL_VERSION].name = "protocol-version";
	arr[WGPEER_A_PROTOCOL_VERSION].type = YNL_PT_U32;
	return arr;
} ();

struct ynl_policy_nest wireguard_wgpeer_nest = {
	.max_attr = static_cast<unsigned int>(WGPEER_A_MAX),
	.table = wireguard_wgpeer_policy.data(),
};

static std::array<ynl_policy_attr,WGDEVICE_A_MAX + 1> wireguard_wgdevice_policy = []() {
	std::array<ynl_policy_attr,WGDEVICE_A_MAX + 1> arr{};
	arr[WGDEVICE_A_UNSPEC].name = "unspec";
	arr[WGDEVICE_A_UNSPEC].type = YNL_PT_REJECT;
	arr[WGDEVICE_A_IFINDEX].name = "ifindex";
	arr[WGDEVICE_A_IFINDEX].type = YNL_PT_U32;
	arr[WGDEVICE_A_IFNAME].name = "ifname";
	arr[WGDEVICE_A_IFNAME].type  = YNL_PT_NUL_STR;
	arr[WGDEVICE_A_PRIVATE_KEY].name = "private-key";
	arr[WGDEVICE_A_PRIVATE_KEY].type = YNL_PT_BINARY;
	arr[WGDEVICE_A_PUBLIC_KEY].name = "public-key";
	arr[WGDEVICE_A_PUBLIC_KEY].type = YNL_PT_BINARY;
	arr[WGDEVICE_A_FLAGS].name = "flags";
	arr[WGDEVICE_A_FLAGS].type = YNL_PT_U32;
	arr[WGDEVICE_A_LISTEN_PORT].name = "listen-port";
	arr[WGDEVICE_A_LISTEN_PORT].type = YNL_PT_U16;
	arr[WGDEVICE_A_FWMARK].name = "fwmark";
	arr[WGDEVICE_A_FWMARK].type = YNL_PT_U32;
	arr[WGDEVICE_A_PEERS].name = "peers";
	arr[WGDEVICE_A_PEERS].type = YNL_PT_NEST;
	arr[WGDEVICE_A_PEERS].nest = &wireguard_wgpeer_nest;
	return arr;
} ();

struct ynl_policy_nest wireguard_wgdevice_nest = {
	.max_attr = static_cast<unsigned int>(WGDEVICE_A_MAX),
	.table = wireguard_wgdevice_policy.data(),
};

/* Common nested types */
int wireguard_wgallowedip_put(struct nlmsghdr *nlh, unsigned int attr_type,
			      const wireguard_wgallowedip&  obj)
{
	struct nlattr *nest;

	nest = ynl_attr_nest_start(nlh, attr_type);
	if (obj.family.has_value()) {
		ynl_attr_put_u16(nlh, WGALLOWEDIP_A_FAMILY, obj.family.value());
	}
	if (obj.ipaddr.size() > 0) {
		ynl_attr_put(nlh, WGALLOWEDIP_A_IPADDR, obj.ipaddr.data(), obj.ipaddr.size());
	}
	if (obj.cidr_mask.has_value()) {
		ynl_attr_put_u8(nlh, WGALLOWEDIP_A_CIDR_MASK, obj.cidr_mask.value());
	}
	if (obj.flags.has_value()) {
		ynl_attr_put_u32(nlh, WGALLOWEDIP_A_FLAGS, obj.flags.value());
	}
	ynl_attr_nest_end(nlh, nest);

	return 0;
}

int wireguard_wgallowedip_parse(struct ynl_parse_arg *yarg,
				const struct nlattr *nested, __u32 idx)
{
	wireguard_wgallowedip *dst = (wireguard_wgallowedip *)yarg->data;
	const struct nlattr *attr;

	dst->idx = idx;

	ynl_attr_for_each_nested(attr, nested) {
		unsigned int type = ynl_attr_type(attr);

		if (type == WGALLOWEDIP_A_FAMILY) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			dst->family = (__u16)ynl_attr_get_u16(attr);
		} else if (type == WGALLOWEDIP_A_IPADDR) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			unsigned int len = ynl_attr_data_len(attr);
			__u8 *data = (__u8*)ynl_attr_data(attr);
			dst->ipaddr.assign(data, data + len);
		} else if (type == WGALLOWEDIP_A_CIDR_MASK) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			dst->cidr_mask = (__u8)ynl_attr_get_u8(attr);
		} else if (type == WGALLOWEDIP_A_FLAGS) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			dst->flags = (__u32)ynl_attr_get_u32(attr);
		}
	}

	return 0;
}

int wireguard_wgpeer_put(struct nlmsghdr *nlh, unsigned int attr_type,
			 const wireguard_wgpeer&  obj)
{
	struct nlattr *array;
	struct nlattr *nest;

	nest = ynl_attr_nest_start(nlh, attr_type);
	if (obj.public_key.size() > 0) {
		ynl_attr_put(nlh, WGPEER_A_PUBLIC_KEY, obj.public_key.data(), obj.public_key.size());
	}
	if (obj.preshared_key.size() > 0) {
		ynl_attr_put(nlh, WGPEER_A_PRESHARED_KEY, obj.preshared_key.data(), obj.preshared_key.size());
	}
	if (obj.flags.has_value()) {
		ynl_attr_put_u32(nlh, WGPEER_A_FLAGS, obj.flags.value());
	}
	if (obj.endpoint.size() > 0) {
		ynl_attr_put(nlh, WGPEER_A_ENDPOINT, obj.endpoint.data(), obj.endpoint.size());
	}
	if (obj.persistent_keepalive_interval.has_value()) {
		ynl_attr_put_u16(nlh, WGPEER_A_PERSISTENT_KEEPALIVE_INTERVAL, obj.persistent_keepalive_interval.value());
	}
	if (obj.last_handshake_time) {
		ynl_attr_put(nlh, WGPEER_A_LAST_HANDSHAKE_TIME, &*obj.last_handshake_time, sizeof(struct __kernel_timespec));
	}
	if (obj.rx_bytes.has_value()) {
		ynl_attr_put_u64(nlh, WGPEER_A_RX_BYTES, obj.rx_bytes.value());
	}
	if (obj.tx_bytes.has_value()) {
		ynl_attr_put_u64(nlh, WGPEER_A_TX_BYTES, obj.tx_bytes.value());
	}
	array = ynl_attr_nest_start(nlh, WGPEER_A_ALLOWEDIPS);
	for (unsigned int i = 0; i < obj.allowedips.size(); i++) {
		wireguard_wgallowedip_put(nlh, i, obj.allowedips[i]);
	}
	ynl_attr_nest_end(nlh, array);
	if (obj.protocol_version.has_value()) {
		ynl_attr_put_u32(nlh, WGPEER_A_PROTOCOL_VERSION, obj.protocol_version.value());
	}
	ynl_attr_nest_end(nlh, nest);

	return 0;
}

int wireguard_wgpeer_parse(struct ynl_parse_arg *yarg,
			   const struct nlattr *nested, __u32 idx)
{
	wireguard_wgpeer *dst = (wireguard_wgpeer *)yarg->data;
	const struct nlattr *attr_allowedips;
	unsigned int n_allowedips = 0;
	const struct nlattr *attr;
	struct ynl_parse_arg parg;
	int i;

	parg.ys = yarg->ys;

	dst->idx = idx;
	if (dst->allowedips.size() > 0) {
		return ynl_error_parse(yarg, "attribute already present (wgpeer.allowedips)");
	}

	ynl_attr_for_each_nested(attr, nested) {
		unsigned int type = ynl_attr_type(attr);

		if (type == WGPEER_A_PUBLIC_KEY) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			unsigned int len = ynl_attr_data_len(attr);
			__u8 *data = (__u8*)ynl_attr_data(attr);
			dst->public_key.assign(data, data + len);
		} else if (type == WGPEER_A_PRESHARED_KEY) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			unsigned int len = ynl_attr_data_len(attr);
			__u8 *data = (__u8*)ynl_attr_data(attr);
			dst->preshared_key.assign(data, data + len);
		} else if (type == WGPEER_A_FLAGS) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			dst->flags = (__u32)ynl_attr_get_u32(attr);
		} else if (type == WGPEER_A_ENDPOINT) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			unsigned int len = ynl_attr_data_len(attr);
			__u8 *data = (__u8*)ynl_attr_data(attr);
			dst->endpoint.assign(data, data + len);
		} else if (type == WGPEER_A_PERSISTENT_KEEPALIVE_INTERVAL) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			dst->persistent_keepalive_interval = (__u16)ynl_attr_get_u16(attr);
		} else if (type == WGPEER_A_LAST_HANDSHAKE_TIME) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			unsigned int len = ynl_attr_data_len(attr);
			unsigned int struct_sz = sizeof(struct __kernel_timespec);
			dst->last_handshake_time.emplace();
			memcpy(&*dst->last_handshake_time, ynl_attr_data(attr), std::min(struct_sz, len));
		} else if (type == WGPEER_A_RX_BYTES) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			dst->rx_bytes = (__u64)ynl_attr_get_u64(attr);
		} else if (type == WGPEER_A_TX_BYTES) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			dst->tx_bytes = (__u64)ynl_attr_get_u64(attr);
		} else if (type == WGPEER_A_ALLOWEDIPS) {
			const struct nlattr *attr2;

			attr_allowedips = attr;
		} else if (type == WGPEER_A_PROTOCOL_VERSION) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			dst->protocol_version = (__u32)ynl_attr_get_u32(attr);
		}
	}

	if (n_allowedips) {
		dst->allowedips.resize(n_allowedips);
		i = 0;
		parg.rsp_policy = &wireguard_wgallowedip_nest;
		ynl_attr_for_each_nested(attr, attr_allowedips) {
			parg.data = &dst->allowedips[i];
			if (wireguard_wgallowedip_parse(&parg, attr, ynl_attr_type(attr))) {
				return YNL_PARSE_CB_ERROR;
			}
			i++;
		}
	}

	return 0;
}

/* ============== WG_CMD_GET_DEVICE ============== */
/* WG_CMD_GET_DEVICE - dump */
int wireguard_get_device_rsp_parse(const struct nlmsghdr *nlh,
				   struct ynl_parse_arg *yarg)
{
	const struct nlattr *attr_peers;
	wireguard_get_device_rsp *dst;
	const struct nlattr *attr;
	struct ynl_parse_arg parg;
	unsigned int n_peers = 0;
	int i;

	dst = (wireguard_get_device_rsp*)yarg->data;
	parg.ys = yarg->ys;

	if (dst->peers.size() > 0) {
		return ynl_error_parse(yarg, "attribute already present (wgdevice.peers)");
	}

	ynl_attr_for_each(attr, nlh, yarg->ys->family->hdr_len) {
		unsigned int type = ynl_attr_type(attr);

		if (type == WGDEVICE_A_IFINDEX) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			dst->ifindex = (__u32)ynl_attr_get_u32(attr);
		} else if (type == WGDEVICE_A_IFNAME) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			dst->ifname.assign(ynl_attr_get_str(attr));
		} else if (type == WGDEVICE_A_PRIVATE_KEY) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			unsigned int len = ynl_attr_data_len(attr);
			__u8 *data = (__u8*)ynl_attr_data(attr);
			dst->private_key.assign(data, data + len);
		} else if (type == WGDEVICE_A_PUBLIC_KEY) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			unsigned int len = ynl_attr_data_len(attr);
			__u8 *data = (__u8*)ynl_attr_data(attr);
			dst->public_key.assign(data, data + len);
		} else if (type == WGDEVICE_A_FLAGS) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			dst->flags = (__u32)ynl_attr_get_u32(attr);
		} else if (type == WGDEVICE_A_LISTEN_PORT) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			dst->listen_port = (__u16)ynl_attr_get_u16(attr);
		} else if (type == WGDEVICE_A_FWMARK) {
			if (ynl_attr_validate(yarg, attr)) {
				return YNL_PARSE_CB_ERROR;
			}
			dst->fwmark = (__u32)ynl_attr_get_u32(attr);
		} else if (type == WGDEVICE_A_PEERS) {
			const struct nlattr *attr2;

			attr_peers = attr;
		}
	}

	if (n_peers) {
		dst->peers.resize(n_peers);
		i = 0;
		parg.rsp_policy = &wireguard_wgpeer_nest;
		ynl_attr_for_each_nested(attr, attr_peers) {
			parg.data = &dst->peers[i];
			if (wireguard_wgpeer_parse(&parg, attr, ynl_attr_type(attr))) {
				return YNL_PARSE_CB_ERROR;
			}
			i++;
		}
	}

	return YNL_PARSE_CB_OK;
}

std::unique_ptr<wireguard_get_device_list>
wireguard_get_device_dump(ynl_cpp::ynl_socket& ys,
			  wireguard_get_device_req& req)
{
	struct ynl_dump_no_alloc_state yds = {};
	struct nlmsghdr *nlh;
	int err;

	auto ret = std::make_unique<wireguard_get_device_list>();
	yds.yarg.ys = ys;
	yds.yarg.rsp_policy = &wireguard_wgdevice_nest;
	yds.yarg.data = ret.get();
	yds.alloc_cb = [](void* arg)->void* {return &(static_cast<wireguard_get_device_list*>(arg)->objs.emplace_back());};
	yds.cb = wireguard_get_device_rsp_parse;
	yds.rsp_cmd = WG_CMD_GET_DEVICE;

	nlh = ynl_gemsg_start_dump(ys, ((struct ynl_sock*)ys)->family_id, WG_CMD_GET_DEVICE, 1);
	((struct ynl_sock*)ys)->req_policy = &wireguard_wgdevice_nest;

	if (req.ifindex.has_value()) {
		ynl_attr_put_u32(nlh, WGDEVICE_A_IFINDEX, req.ifindex.value());
	}
	if (req.ifname.size() > 0) {
		ynl_attr_put_str(nlh, WGDEVICE_A_IFNAME, req.ifname.data());
	}

	err = ynl_exec_dump_no_alloc(ys, nlh, &yds);
	if (err < 0) {
		return nullptr;
	}

	return ret;
}

/* ============== WG_CMD_SET_DEVICE ============== */
/* WG_CMD_SET_DEVICE - do */
int wireguard_set_device(ynl_cpp::ynl_socket& ys,
			 wireguard_set_device_req& req)
{
	struct ynl_req_state yrs = { .yarg = { .ys = ys, }, };
	struct nlmsghdr *nlh;
	struct nlattr *array;
	int err;

	nlh = ynl_gemsg_start_req(ys, ((struct ynl_sock*)ys)->family_id, WG_CMD_SET_DEVICE, 1);
	((struct ynl_sock*)ys)->req_policy = &wireguard_wgdevice_nest;

	if (req.ifindex.has_value()) {
		ynl_attr_put_u32(nlh, WGDEVICE_A_IFINDEX, req.ifindex.value());
	}
	if (req.ifname.size() > 0) {
		ynl_attr_put_str(nlh, WGDEVICE_A_IFNAME, req.ifname.data());
	}
	if (req.private_key.size() > 0) {
		ynl_attr_put(nlh, WGDEVICE_A_PRIVATE_KEY, req.private_key.data(), req.private_key.size());
	}
	if (req.public_key.size() > 0) {
		ynl_attr_put(nlh, WGDEVICE_A_PUBLIC_KEY, req.public_key.data(), req.public_key.size());
	}
	if (req.flags.has_value()) {
		ynl_attr_put_u32(nlh, WGDEVICE_A_FLAGS, req.flags.value());
	}
	if (req.listen_port.has_value()) {
		ynl_attr_put_u16(nlh, WGDEVICE_A_LISTEN_PORT, req.listen_port.value());
	}
	if (req.fwmark.has_value()) {
		ynl_attr_put_u32(nlh, WGDEVICE_A_FWMARK, req.fwmark.value());
	}
	array = ynl_attr_nest_start(nlh, WGDEVICE_A_PEERS);
	for (unsigned int i = 0; i < req.peers.size(); i++) {
		wireguard_wgpeer_put(nlh, i, req.peers[i]);
	}
	ynl_attr_nest_end(nlh, array);

	err = ynl_exec(ys, nlh, &yrs);
	if (err < 0) {
		return -1;
	}

	return 0;
}

const struct ynl_family ynl_wireguard_family =  {
	.name		= "wireguard",
	.hdr_len	= sizeof(struct genlmsghdr),
};
const struct ynl_family& get_ynl_wireguard_family() {
	return ynl_wireguard_family;
};
} //namespace ynl_cpp
