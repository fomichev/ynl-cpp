/* SPDX-License-Identifier: ((GPL-2.0 WITH Linux-syscall-note) OR BSD-3-Clause) */
/* Do not edit directly, auto-generated from: */
/*	 */
/* YNL-GEN user header */

#ifndef _LINUX_DEV_ENERGYMODEL_GEN_H
#define _LINUX_DEV_ENERGYMODEL_GEN_H

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

#include <linux/dev_energymodel.h>

namespace ynl_cpp {
const struct ynl_family& get_ynl_dev_energymodel_family();

/* Enums */
std::string_view dev_energymodel_op_str(int op);
std::string_view
dev_energymodel_perf_state_flags_str(dev_energymodel_perf_state_flags value);
std::string_view
dev_energymodel_perf_domain_flags_str(dev_energymodel_perf_domain_flags value);

/* Common nested types */
struct dev_energymodel_perf_state {
	std::optional<__u64> performance;
	std::optional<__u64> frequency;
	std::optional<__u64> power;
	std::optional<__u64> cost;
	std::optional<__u64> flags;
};

/* ============== DEV_ENERGYMODEL_CMD_GET_PERF_DOMAINS ============== */
/* DEV_ENERGYMODEL_CMD_GET_PERF_DOMAINS - do */
struct dev_energymodel_get_perf_domains_req {
	std::optional<__u32> perf_domain_id;
};

struct dev_energymodel_get_perf_domains_rsp {
	std::optional<__u32> perf_domain_id;
	std::optional<__u64> flags;
	std::vector<__u64> cpus;
};

/*
 * Get the list of information for all performance domains.
 */
std::unique_ptr<dev_energymodel_get_perf_domains_rsp>
dev_energymodel_get_perf_domains(ynl_cpp::ynl_socket& ys,
				 dev_energymodel_get_perf_domains_req& req);

/* DEV_ENERGYMODEL_CMD_GET_PERF_DOMAINS - dump */
struct dev_energymodel_get_perf_domains_list {
	std::list<dev_energymodel_get_perf_domains_rsp> objs;
};

std::unique_ptr<dev_energymodel_get_perf_domains_list>
dev_energymodel_get_perf_domains_dump(ynl_cpp::ynl_socket& ys);

/* ============== DEV_ENERGYMODEL_CMD_GET_PERF_TABLE ============== */
/* DEV_ENERGYMODEL_CMD_GET_PERF_TABLE - do */
struct dev_energymodel_get_perf_table_req {
	std::optional<__u32> perf_domain_id;
};

struct dev_energymodel_get_perf_table_rsp {
	std::optional<__u32> perf_domain_id;
	std::vector<dev_energymodel_perf_state> perf_state;
};

/*
 * Get the energy model table of a performance domain.
 */
std::unique_ptr<dev_energymodel_get_perf_table_rsp>
dev_energymodel_get_perf_table(ynl_cpp::ynl_socket& ys,
			       dev_energymodel_get_perf_table_req& req);

/* DEV_ENERGYMODEL_CMD_GET_PERF_TABLE - notify */
struct dev_energymodel_get_perf_table_ntf {
	__u16 family;
	__u8 cmd;
	struct ynl_ntf_base_type* next;
	void (*free)(struct ynl_ntf_base_type* ntf);
	dev_energymodel_get_perf_table_rsp obj __attribute__((aligned(8)));
};

/* DEV_ENERGYMODEL_CMD_PERF_DOMAIN_DELETED - event */
struct dev_energymodel_perf_domain_deleted_rsp {
	std::optional<__u32> perf_domain_id;
};

struct dev_energymodel_perf_domain_deleted {
	__u16 family;
	__u8 cmd;
	struct ynl_ntf_base_type* next;
	void (*free)(struct ynl_ntf_base_type* ntf);
	dev_energymodel_perf_domain_deleted_rsp obj __attribute__((aligned(8)));
};

} //namespace ynl_cpp
#endif /* _LINUX_DEV_ENERGYMODEL_GEN_H */
